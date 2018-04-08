# stacktrace-demangled
[stacktrace-demangled](http://panthema.net/2008/0901-stacktrace-demangled/ "title")


## Requirements
 * `-g` compilation option
 * `-rdynamic` linker option
  * `backtrace()`, `backtrace_symbols()` to get stack trace [doc](https://www.gnu.org/software/libc/manual/html_node/Backtraces.html)
 * `__cxa_demangle` to have nice C++ function [doc](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a01696.html)
 
## Features
 * C and C++ names

## What missing
 * no line numbers   
 
## Onboarding to new project
Onboarding is very simple, no dependencies, however it does not provide line numbers.
 * define [helper function](/backtrace_symbol/src/stacktrace.h)
 * `-g` compilation option
 * `-rdynamic` link option
 
## Troubleshooting
  * no stack trace - check if `-g` and `-rdynamic` options are active

## Compilation and Link Without `-rdynamic` linker option

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++  -o "backtrace_symbol"  ./src/backtrace_symbol.o 
```
### Output

```C
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xd87
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xd08
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xdae
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xd1b
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xdd2
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xd27
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xcad
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xeb8
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xe8a
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xe5c
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xe2e
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xe00
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0xd49
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : ()+0x81a
  
```

## Compilation and Link With `-rdynamic` linker option

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++ -rdynamic -o "backtrace_symbol"  ./src/backtrace_symbol.o   
```

### Output
```
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : Nu::Alpha<int>::Beta::func(int)+0x23
  .../backtrace_symbol/Debug/backtrace_symbol : main()+0x58
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : Nu::Alpha<char*>::Beta::func(char*)+0x24
  .../backtrace_symbol/Debug/backtrace_symbol : main()+0x6b
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : Nu::Alpha<Nu::Alpha<std::map<int, double, std::less<int>, std::allocator<std::pair<int const, double> > > > >::Beta::func()+0x20
  .../backtrace_symbol/Debug/backtrace_symbol : main()+0x77
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a
stack trace:
  .../backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<0>(double)+0x25
  .../backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<1>(double)+0x2a
  .../backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<2>(double)+0x2a
  .../backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<3>(double)+0x2a
  .../backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<4>(double)+0x2a
  .../backtrace_symbol/Debug/backtrace_symbol : void Nu::Gamma::unroll<5>(double)+0x2a
  .../backtrace_symbol/Debug/backtrace_symbol : main()+0x99
  /lib/x86_64-linux-gnu/libc.so.6 : __libc_start_main()+0xf1
  .../backtrace_symbol/Debug/backtrace_symbol : _start()+0x2a

```
