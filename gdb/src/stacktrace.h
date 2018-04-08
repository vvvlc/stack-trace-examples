// stacktrace.h (c) 2008, Timo Bingmann from http://idlebox.net/
// published under the WTFPL v2.0

#ifndef _STACKTRACE_H_
#define _STACKTRACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


///------
/** Print a demangled stack backtrace of the caller function to FILE* out. */
static inline void print_stacktrace(FILE *out = stderr, unsigned int max_frames = 63)
{
    char buffer[256];

    sprintf (buffer, "gdb -batch -ex bt -pid %ld", (long) getpid());
    system(buffer);
}



#endif // _STACKTRACE_H_
