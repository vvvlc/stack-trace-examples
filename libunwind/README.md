# libunwind
[libunwind](https://www.nongnu.org/libunwind/index.html) [example](http://blog.bigpixel.ro/stack-unwinding-stack-trace-with-gcc/)

## Requirements
 *  `-g` compile
 *  `libunwind` library
 *  `addr2line` utility
     *  `argv[0]` input parameter
     *  `/proc/pid/maps` to identify offset of module in memory 
 
 
## Features
 * C names only
 * filenames and line numbers ??? - only when virtual address matches physical address in file, see troubleshooting.

## What missing
 * C++ names are mangled (easy to fix) 
 
## Onboarning to new project
It is easy to onboard.
 * define [helper function](/libunwind/src/stacktrace.h)
 * add `-g` compilation option
 * add `-lunwind -lunwind-x86_64` linker options, note: instal via `sudo apt install libunwind-dev`


## Troubleshooting 
### Stacktrace contains file unkown line 0 

When stacktrace contains file *unkown* line *0* for example
   
```
__libc_start_main in file unkown line 0

```

There is a [dirty solution](https://stackoverflow.com/questions/7648642/how-to-use-the-addr2line-command-in-linux).
   *  run `cat /proc/17341/maps | grep r-xp`  where `17341` is a pid of current process
   *  `555555554000-555555557000 r-xp 00000000 08:06 490979  /home/vlcvi01/Dropbox/eclipse-workspaces/arduino-test/stacktesycpp/Debug/stacktesycpp`, then take 1st address `0x555555554000` and subtract it from `addr` variable in `getFileAndLine` of `stacktrace.h`, then `addr2line` start providing reasonable values.
This hack is not part of source code, I used a hard coded value.  


## Compilation and Link

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++ -o "libunwind"  ./src/backtrace_symbol.o   -lunwind -lunwind-x86_64
```

### Output
```C
_ZN2Nu5AlphaIiE4Beta4funcEi in file unkown line 0
main in file unkown line 0
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0
_ZN2Nu5AlphaIPcE4Beta4funcES1_ in file unkown line 0
main in file unkown line 0
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0
_ZN2Nu5AlphaINS0_ISt3mapIidSt4lessIiESaISt4pairIKidEEEEEE4Beta4funcEv in file unkown line 0
main in file unkown line 0
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0
_ZN2Nu5Gamma6unrollILi0EEEvd in file unkown line 0
_ZN2Nu5Gamma6unrollILi1EEEvd in file unkown line 0
_ZN2Nu5Gamma6unrollILi2EEEvd in file unkown line 0
_ZN2Nu5Gamma6unrollILi3EEEvd in file unkown line 0
_ZN2Nu5Gamma6unrollILi4EEEvd in file unkown line 0
_ZN2Nu5Gamma6unrollILi5EEEvd in file unkown line 0
main in file unkown line 0
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0
```

## Compilation and Link with hard-coded address

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++ -o "libunwind"  ./src/backtrace_symbol.o   -lunwind -lunwind-x86_64
```

### Output
```C
_ZN2Nu5AlphaIiE4Beta4funcEi in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 16
main in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 41
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0
_ZN2Nu5AlphaIPcE4Beta4funcES1_ in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 16
main in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 42
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0
_ZN2Nu5AlphaINS0_ISt3mapIidSt4lessIiESaISt4pairIKidEEEEEE4Beta4funcEv in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 13
main in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 43
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0
_ZN2Nu5Gamma6unrollILi0EEEvd in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 31
_ZN2Nu5Gamma6unrollILi1EEEvd in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 25
_ZN2Nu5Gamma6unrollILi2EEEvd in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 25
_ZN2Nu5Gamma6unrollILi3EEEvd in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 25
_ZN2Nu5Gamma6unrollILi4EEEvd in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 25
_ZN2Nu5Gamma6unrollILi5EEEvd in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 25
main in file /home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/libunwind/Debug/../src/backtrace_symbol.cpp line 44
__libc_start_main in file unkown line 0
_start in file unkown line 0
 in file unkown line 0


```
