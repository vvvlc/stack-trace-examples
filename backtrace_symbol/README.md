# stacktrace-demangled
[stacktrace-demangled](http://panthema.net/2008/0901-stacktrace-demangled/ "title")


## Requirements
 * `-g` compilation
 * `-rdynamic` linking
 
## Features
 * C and C++ names

## What missing
 * no line numbers   
 
## Deployment
 * header only
 * `backtrace()`, `backtrace_symbols()` to get stack trace [doc](https://www.gnu.org/software/libc/manual/html_node/Backtraces.html)
 * `__cxa_demangle` to have nice C++ function [doc](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a01696.html)
 
## Troubleshooting
  * no stack trace - check if `-g` and `-rdynamic` options are active

## Compilation and Link Without `-rdynamic` linker options.

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++  -o "backtrace_symbol"  ./src/backtrace_symbol.o 
```
### Output

```C
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xd87
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xd08
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xdae
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xd1b
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xdd2
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xd27
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xcad
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xeb8
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xe8a
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xe5c
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xe2e
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xe00
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0xd49
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
 
```

## Compilation and Link With `-rdynamic` linker options.

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++ -rdynamic -o "backtrace_symbol"  ./src/backtrace_symbol.o   
```

### Output
```
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : Nu::Alpha<int>::Beta::func(int)+0x23
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : main()+0x58
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : Nu::Alpha<char*>::Beta::func(char*)+0x24
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : main()+0x6b
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : Nu::Alpha<Nu::Alpha<std::map<int, double, std::less<int>, std::allocator<std::pair<int const, double> > > > >::Beta::func()+0x20
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : main()+0x77
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a
stack trace:
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<0>(double)+0x25
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<1>(double)+0x2a
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<2>(double)+0x2a
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<3>(double)+0x2a
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<4>(double)+0x2a
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<5>(double)+0x2a
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : main()+0x99
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a

```