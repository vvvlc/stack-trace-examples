# libbacktrace
[libbacktrace](https://github.com/ianlancetaylor/libbacktrace) [example](https://gist.github.com/tsaarni/44f8080e671683b7c870)

## Requirements
 *  `-g` compile
 *  `libbacktrace` library
 *  `cxxabi.h`
 
 
## Features
 * C/C++ names
 * filenames and line numbers

 
## Deployment
 *  `libbacktrace` library


## Compilation and Link

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/backtrace_symbol.o" "../src/backtrace_symbol.cpp"
g++  -o "libbacktrace"  ./src/backtrace_symbol.o   -lbacktrace
```

### Output
```C
Backtrace:
0x559fa2f9f3de print_stacktrace 	../src/stacktrace.h:52
0x559fa2f9f54c Nu::Alpha<int>::Beta::func(int) 	../src/backtrace_symbol.cpp:15
0x559fa2f9f46e main 	../src/backtrace_symbol.cpp:40
Backtrace:
0x559fa2f9f3de print_stacktrace 	../src/stacktrace.h:52
0x559fa2f9f573 Nu::Alpha<char*>::Beta::func(char*) 	../src/backtrace_symbol.cpp:15
0x559fa2f9f481 main 	../src/backtrace_symbol.cpp:41
Backtrace:
0x559fa2f9f3de print_stacktrace 	../src/stacktrace.h:52
0x559fa2f9f597 Nu::Alpha<Nu::Alpha<std::map<int, double, std::less<int>, std::allocator<std::pair<int const, double> > > > >::Beta::func() 	../src/backtrace_symbol.cpp:12
0x559fa2f9f48d main 	../src/backtrace_symbol.cpp:42
Backtrace:
0x559fa2f9f3de print_stacktrace 	../src/stacktrace.h:52
0x559fa2f9f406 void Nu::Gamma::unroll<0>(double) 	../src/backtrace_symbol.cpp:30
0x559fa2f9f67d void Nu::Gamma::unroll<1>(double) 	../src/backtrace_symbol.cpp:24
0x559fa2f9f64f void Nu::Gamma::unroll<2>(double) 	../src/backtrace_symbol.cpp:24
0x559fa2f9f621 void Nu::Gamma::unroll<3>(double) 	../src/backtrace_symbol.cpp:24
0x559fa2f9f5f3 void Nu::Gamma::unroll<4>(double) 	../src/backtrace_symbol.cpp:24
0x559fa2f9f5c5 void Nu::Gamma::unroll<5>(double) 	../src/backtrace_symbol.cpp:24
0x559fa2f9f4af main 	../src/backtrace_symbol.cpp:43

```
