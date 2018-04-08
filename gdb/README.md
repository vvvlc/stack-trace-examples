# GDB
[Gdb actually provides a better stack trace with debugging information. It even provides parameter values.](https://www.reddit.com/r/programming/comments/dbj5s/stack_unwinding_stack_trace_with_gcc_i_always/c0yz8jg/) and [here](https://www.reddit.com/r/programming/comments/dbj5s/stack_unwinding_stack_trace_with_gcc_i_always/)


## Requirements
 * system setup
    *  `sudo gdb -batch -ex bt -pid %ld` - problem with password 
    *  `echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope` - not a permanent change
    *  `/etc/sysctl.d/10-ptrace.conf` set `kernel.yama.ptrace_scope = 0` - security problem, anyone can attach to any process for example to `sshd` to steal private ssh keys.  
 *  `-g` partially required during compilation if you want to see parameters and filenames including line numbers
 
 
## Features
 * C and C++ names
 * filenames and line numbers
 * value of parameters of invoked functions `print_stacktrace (out=0x7f6708c69640 <_IO_2_1_stderr_>, max_frames=63) at ../src/stacktrace.h:19`

## What missing
 * nothing 
 
## Deployment
 * header only
 * `system()` to invoke gdb
 * gdb debugger
 * system setup !!!

## Troubleshooting 
  * I found this to be incompatible with the use of valgrind (probably due to Valgrind's use of a virtual machine). It also doesn't work when you are running the program inside of a gdb session (can't apply a second instance of "ptrace" to a process). [see](https://stackoverflow.com/questions/4636456/how-to-get-a-stack-trace-for-c-using-gcc-with-line-number-information)
  * error message instead of stack trace -- see requirements *system setup*
   
```
	Could not attach to process.  If your uid matches the uid of the target
	process, check the setting of /proc/sys/kernel/yama/ptrace_scope, or try
	again as the root user.  For more details, see /etc/sysctl.d/10-ptrace.conf
	ptrace: Operation not permitted.
```

## Compilation and Link

```sh
g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/
g++  -o "gdb"  ./src/backtrace_symbol.o  
```

### Output
```C
0x00007f67089668fa in __GI___waitpid (pid=974, stat_loc=stat_loc@entry=0x7ffc4d79b438, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f67089668fa in __GI___waitpid (pid=974, stat_loc=stat_loc@entry=0x7ffc4d79b438, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f67088d59cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x00005595d46507e3 in print_stacktrace (out=0x7f6708c69640 <_IO_2_1_stderr_>, max_frames=63) at ../src/stacktrace.h:19
#3  0x00005595d46508f9 in Nu::Alpha<int>::Beta::func (this=0x7ffc4d79b72f) at ../src/backtrace_symbol.cpp:15
#4  0x00005595d465087a in main () at ../src/backtrace_symbol.cpp:40
0x00007f67089668fa in __GI___waitpid (pid=980, stat_loc=stat_loc@entry=0x7ffc4d79b438, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f67089668fa in __GI___waitpid (pid=980, stat_loc=stat_loc@entry=0x7ffc4d79b438, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f67088d59cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x00005595d46507e3 in print_stacktrace (out=0x7f6708c69640 <_IO_2_1_stderr_>, max_frames=63) at ../src/stacktrace.h:19
#3  0x00005595d4650920 in Nu::Alpha<char*>::Beta::func (this=0x7ffc4d79b72f) at ../src/backtrace_symbol.cpp:15
#4  0x00005595d465088d in main () at ../src/backtrace_symbol.cpp:41
0x00007f67089668fa in __GI___waitpid (pid=986, stat_loc=stat_loc@entry=0x7ffc4d79b438, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f67089668fa in __GI___waitpid (pid=986, stat_loc=stat_loc@entry=0x7ffc4d79b438, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f67088d59cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x00005595d46507e3 in print_stacktrace (out=0x7f6708c69640 <_IO_2_1_stderr_>, max_frames=63) at ../src/stacktrace.h:19
#3  0x00005595d4650944 in Nu::Alpha<Nu::Alpha<std::map<int, double, std::less<int>, std::allocator<std::pair<int const, double> > > > >::Beta::func (this=0x7ffc4d79b72f) at ../src/backtrace_symbol.cpp:12
#4  0x00005595d4650899 in main () at ../src/backtrace_symbol.cpp:42
0x00007f67089668fa in __GI___waitpid (pid=992, stat_loc=stat_loc@entry=0x7ffc4d79b348, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f67089668fa in __GI___waitpid (pid=992, stat_loc=stat_loc@entry=0x7ffc4d79b348, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f67088d59cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x00005595d46507e3 in print_stacktrace (out=0x7f6708c69640 <_IO_2_1_stderr_>, max_frames=63) at ../src/stacktrace.h:19
#3  0x00005595d465081f in Nu::Gamma::unroll<0> (this=0x7ffc4d79b72f) at ../src/backtrace_symbol.cpp:30
#4  0x00005595d4650a2a in Nu::Gamma::unroll<1> (this=0x7ffc4d79b72f, d=42) at ../src/backtrace_symbol.cpp:24
#5  0x00005595d46509fc in Nu::Gamma::unroll<2> (this=0x7ffc4d79b72f, d=42) at ../src/backtrace_symbol.cpp:24
#6  0x00005595d46509ce in Nu::Gamma::unroll<3> (this=0x7ffc4d79b72f, d=42) at ../src/backtrace_symbol.cpp:24
#7  0x00005595d46509a0 in Nu::Gamma::unroll<4> (this=0x7ffc4d79b72f, d=42) at ../src/backtrace_symbol.cpp:24
#8  0x00005595d4650972 in Nu::Gamma::unroll<5> (this=0x7ffc4d79b72f, d=42) at ../src/backtrace_symbol.cpp:24
#9  0x00005595d46508bb in main () at ../src/backtrace_symbol.cpp:43

```

## Compilation and Link without `-g`

```sh
g++ -O0 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/backtrace_symbol.d" -MT"src/backtrace_symbol.o" -o "src/
g++  -o "gdb"  ./src/backtrace_symbol.o  
```

### Output
```C
0x00007f275af388fa in __GI___waitpid (pid=2092, stat_loc=stat_loc@entry=0x7fff3ebf4c08, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f275af388fa in __GI___waitpid (pid=2092, stat_loc=stat_loc@entry=0x7fff3ebf4c08, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f275aea79cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x000056157e0577e3 in print_stacktrace(_IO_FILE*, unsigned int) ()
#3  0x000056157e0578f9 in Nu::Alpha<int>::Beta::func(int) ()
#4  0x000056157e05787a in main ()
0x00007f275af388fa in __GI___waitpid (pid=2103, stat_loc=stat_loc@entry=0x7fff3ebf4c08, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f275af388fa in __GI___waitpid (pid=2103, stat_loc=stat_loc@entry=0x7fff3ebf4c08, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f275aea79cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x000056157e0577e3 in print_stacktrace(_IO_FILE*, unsigned int) ()
#3  0x000056157e057920 in Nu::Alpha<char*>::Beta::func(char*) ()
#4  0x000056157e05788d in main ()
0x00007f275af388fa in __GI___waitpid (pid=2120, stat_loc=stat_loc@entry=0x7fff3ebf4c08, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f275af388fa in __GI___waitpid (pid=2120, stat_loc=stat_loc@entry=0x7fff3ebf4c08, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f275aea79cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x000056157e0577e3 in print_stacktrace(_IO_FILE*, unsigned int) ()
#3  0x000056157e057944 in Nu::Alpha<Nu::Alpha<std::map<int, double, std::less<int>, std::allocator<std::pair<int const, double> > > > >::Beta::func() ()
#4  0x000056157e057899 in main ()
0x00007f275af388fa in __GI___waitpid (pid=2128, stat_loc=stat_loc@entry=0x7fff3ebf4b18, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
29	../sysdeps/unix/sysv/linux/waitpid.c: No such file or directory.
#0  0x00007f275af388fa in __GI___waitpid (pid=2128, stat_loc=stat_loc@entry=0x7fff3ebf4b18, options=options@entry=0) at ../sysdeps/unix/sysv/linux/waitpid.c:29
#1  0x00007f275aea79cb in do_system (line=<optimized out>) at ../sysdeps/posix/system.c:148
#2  0x000056157e0577e3 in print_stacktrace(_IO_FILE*, unsigned int) ()
#3  0x000056157e05781f in void Nu::Gamma::unroll<0>(double) ()
#4  0x000056157e057a2a in void Nu::Gamma::unroll<1>(double) ()
#5  0x000056157e0579fc in void Nu::Gamma::unroll<2>(double) ()
#6  0x000056157e0579ce in void Nu::Gamma::unroll<3>(double) ()
#7  0x000056157e0579a0 in void Nu::Gamma::unroll<4>(double) ()
#8  0x000056157e057972 in void Nu::Gamma::unroll<5>(double) ()
#9  0x000056157e0578bb in main ()


```
