# libbacktrace
[libbacktrace](https://github.com/ianlancetaylor/libbacktrace) [example](https://gist.github.com/tsaarni/44f8080e671683b7c870)

## Requirements
 *  `-g` compile
 *  `backward.hpp` library
 
 
## Features
 * C/C++ names
 * filenames and line numbers

 
## Deployment
 *  `backward.hpp` single header file
 *  `libdw` library

## Compilation and Link

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++  -o "backward"  ./src/backtrace_symbol.o   -ldw
```

### Output
```C
Stack trace (most recent call last):
#7    Object "", at 0xffffffffffffffff, in 
#6    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148069, in _start
#5    Object "/lib/x86_64-linux-gnu/libc-2.26.so", at 0x7fe5464671c0, in __libc_start_main
      Source "../csu/libc-start.c", line 308, in __libc_start_main [0x7fe5464671c0]
#4    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b1482d8, in main
      Source "../src/backtrace_symbol.cpp", line 40, in main [0x55c96b1482d8]
#3    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14c03a, in Nu::Alpha<int>::Beta::func(int)
      Source "../src/backtrace_symbol.cpp", line 15, in func [0x55c96b14c03a]
#2    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148194, in print_stacktrace(_IO_FILE*, unsigned int)
      Source "../src/stacktrace.h", line 21, in print_stacktrace [0x55c96b148194]
#1    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148b1f, in backward::StackTraceImpl<backward::system_tag::linux_tag>::load_here(unsigned long)
      Source "../src/backward.hpp", line 705, in load_here [0x55c96b148b1f]
#0    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14b059, in unsigned long backward::details::unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback>(backward::StackTraceImpl<backward::system_tag::linux_tag>::callback, unsigned long)
      Source "../src/backward.hpp", line 689, in unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback> [0x55c96b14b059]
Stack trace (most recent call last):
#7    Object "", at 0xffffffffffffffff, in 
#6    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148069, in _start
#5    Object "/lib/x86_64-linux-gnu/libc-2.26.so", at 0x7fe5464671c0, in __libc_start_main
      Source "../csu/libc-start.c", line 308, in __libc_start_main [0x7fe5464671c0]
#4    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b1482eb, in main
      Source "../src/backtrace_symbol.cpp", line 41, in main [0x55c96b1482eb]
#3    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14c061, in Nu::Alpha<char*>::Beta::func(char*)
      Source "../src/backtrace_symbol.cpp", line 15, in func [0x55c96b14c061]
#2    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148194, in print_stacktrace(_IO_FILE*, unsigned int)
      Source "../src/stacktrace.h", line 21, in print_stacktrace [0x55c96b148194]
#1    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148b1f, in backward::StackTraceImpl<backward::system_tag::linux_tag>::load_here(unsigned long)
      Source "../src/backward.hpp", line 705, in load_here [0x55c96b148b1f]
#0    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14b059, in unsigned long backward::details::unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback>(backward::StackTraceImpl<backward::system_tag::linux_tag>::callback, unsigned long)
      Source "../src/backward.hpp", line 689, in unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback> [0x55c96b14b059]
Stack trace (most recent call last):
#7    Object "", at 0xffffffffffffffff, in 
#6    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148069, in _start
#5    Object "/lib/x86_64-linux-gnu/libc-2.26.so", at 0x7fe5464671c0, in __libc_start_main
      Source "../csu/libc-start.c", line 308, in __libc_start_main [0x7fe5464671c0]
#4    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b1482f7, in main
      Source "../src/backtrace_symbol.cpp", line 42, in main [0x55c96b1482f7]
#3    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14c085, in Nu::Alpha<Nu::Alpha<std::map<int, double, std::less<int>, std::allocator<std::pair<int const, double> > > > >::Beta::func()
      Source "../src/backtrace_symbol.cpp", line 12, in func [0x55c96b14c085]
#2    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148194, in print_stacktrace(_IO_FILE*, unsigned int)
      Source "../src/stacktrace.h", line 21, in print_stacktrace [0x55c96b148194]
#1    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148b1f, in backward::StackTraceImpl<backward::system_tag::linux_tag>::load_here(unsigned long)
      Source "../src/backward.hpp", line 705, in load_here [0x55c96b148b1f]
#0    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14b059, in unsigned long backward::details::unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback>(backward::StackTraceImpl<backward::system_tag::linux_tag>::callback, unsigned long)
      Source "../src/backward.hpp", line 689, in unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback> [0x55c96b14b059]
Stack trace (most recent call last):
#12   Object "", at 0xffffffffffffffff, in 
#11   Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148069, in _start
#10   Object "/lib/x86_64-linux-gnu/libc-2.26.so", at 0x7fe5464671c0, in __libc_start_main
      Source "../csu/libc-start.c", line 308, in __libc_start_main [0x7fe5464671c0]
#9    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148319, in main
      Source "../src/backtrace_symbol.cpp", line 43, in main [0x55c96b148319]
#8    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14c0b3, in void Nu::Gamma::unroll<5>(double)
      Source "../src/backtrace_symbol.cpp", line 24, in unroll<5> [0x55c96b14c0b3]
#7    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14d945, in void Nu::Gamma::unroll<4>(double)
      Source "../src/backtrace_symbol.cpp", line 24, in unroll<4> [0x55c96b14d945]
#6    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14f3fb, in void Nu::Gamma::unroll<3>(double)
      Source "../src/backtrace_symbol.cpp", line 24, in unroll<3> [0x55c96b14f3fb]
#5    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b150493, in void Nu::Gamma::unroll<2>(double)
      Source "../src/backtrace_symbol.cpp", line 24, in unroll<2> [0x55c96b150493]
#4    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b150f41, in void Nu::Gamma::unroll<1>(double)
      Source "../src/backtrace_symbol.cpp", line 24, in unroll<1> [0x55c96b150f41]
#3    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148270, in void Nu::Gamma::unroll<0>(double)
      Source "../src/backtrace_symbol.cpp", line 30, in unroll<0> [0x55c96b148270]
#2    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148194, in print_stacktrace(_IO_FILE*, unsigned int)
      Source "../src/stacktrace.h", line 21, in print_stacktrace [0x55c96b148194]
#1    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b148b1f, in backward::StackTraceImpl<backward::system_tag::linux_tag>::load_here(unsigned long)
      Source "../src/backward.hpp", line 705, in load_here [0x55c96b148b1f]
#0    Object "/home/vlcvi01/Dropbox/eclipse-workspaces/stacktrace/backward/Debug/backward", at 0x55c96b14b059, in unsigned long backward::details::unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback>(backward::StackTraceImpl<backward::system_tag::linux_tag>::callback, unsigned long)
      Source "../src/backward.hpp", line 689, in unwind<backward::StackTraceImpl<backward::system_tag::linux_tag>::callback> [0x55c96b14b059]


```