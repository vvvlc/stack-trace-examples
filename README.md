# stack-trace-examples
Examples how to generate stack-trace for C/C++ via various libraries

This is a little attempt to compare various techniques to genereta a nice stack trace in C/C++. 
Definition of a nice stack-trace:
 * filename
 * line number
 * name of function
 
 Example of "nice" stack-trace via [backward-cpp](/stack-trace-examples/tree/master/backward):
 ```C
...
#4    Object ".../Debug/backward", at 0x55c96b1482d8, in main
       Source "../src/backtrace_symbol.cpp", line 40, in main [0x55c96b1482d8]
#3    Object ".../Debug/backward", at 0x55c96b14c03a, in Nu::Alpha<int>::Beta::func(int)
       Source "../src/backtrace_symbol.cpp", line 15, in func [0x55c96b14c03a]
...
 ```

## Comparison
I compared 4 different methods/libraries
 * [backtrace](/backtrace_symbol) - linux [`backtrace()` and  `backtrace_symbols()`](https://www.gnu.org/software/libc/manual/html_node/Backtraces.html) to get stack trace
 * [gdb](/gdb) - a gdb call [`gdb -batch -ex bt -pid 9999`](https://www.reddit.com/r/programming/comments/dbj5s/stack_unwinding_stack_trace_with_gcc_i_always/)
 * [libunwind](/libunwind) - [`libunwind`](https://www.nongnu.org/libunwind/index.html) and `addr2line`
 * [libbacktrace](/libbacktrace) - [`libbacktrace`](https://github.com/ianlancetaylor/libbacktrace)
 * [backward-cpp](/backward) - [`backward-cpp`](https://github.com/bombela/backward-cpp) and `'libdw`
 
 ### Test Program
 I used a [test program](http://panthema.net/2008/0901-stacktrace-demangled/)
 ```C++ {.line-numbers}
#include "stacktrace.h"
#include <map>

namespace Nu {

template<typename Type>
struct Alpha
{
    struct Beta
    {
	void func() {
	    print_stacktrace();
	}
	void func(Type) {
	    print_stacktrace();
	}
    };
};

struct Gamma
{
    template <int N>
    void unroll(double d) {
	unroll<N-1>(d);
    }
};

template<>
void Gamma::unroll<0>(double) {
    print_stacktrace();
}

} // namespace Nu

int main()
{
    Nu::Alpha<int>::Beta().func(42);
    Nu::Alpha<char*>::Beta().func("42");
    Nu::Alpha< Nu::Alpha< std::map<int, double> > >::Beta().func();
    Nu::Gamma().unroll<5>(42.0);
}
 ```
 
 ### Results
|   | [backtrace](/backtrace_symbol)  |  [gdb](/gdb) |  [libunwind](/libunwind)   | [libbacktrace](/libbacktrace)   |  [backward-cpp](/backward)  |
|---|---|---|---|---|---|
| `-g`         | Yes  | Yes  | Yes  | Yes  | Yes  |
| `-rdynamic`  | Yes   | No  | No  | No  | No  |
|  dependacies | none  | `gdb`  | `libunwind`, `libunwind-x86_64`  | `libbacktrace`  | `libdw`, `backward.hpp`   |
| complexity of onboarding | very simple | medium | simple | very simple | simple|
| filename, function, line numbers| no line numbers | all + parameters | all | all | all | 

Note: click headers to see example of generated stack-trace.

I have to admit onborading of all methods for generation of stack-trace was fairly simple on Ubuntu.
My personal winners are [backward-cpp](/backward) and [libbacktrace](/libbacktrace).
