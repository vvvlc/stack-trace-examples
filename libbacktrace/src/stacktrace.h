// stacktrace.h (c) 2008, Timo Bingmann from http://idlebox.net/
// published under the WTFPL v2.0

#ifndef _STACKTRACE_H_
#define _STACKTRACE_H_

#include <iostream>

#include <string.h>
#include <backtrace.h>
#include <cxxabi.h>

static int
full_callback(void *data __attribute__((unused)), uintptr_t pc,
              const char *filename, int lineno, const char *function)
{
   char *realname = nullptr;
   int demangle_status;

   realname = abi::__cxa_demangle(function, 0, 0, &demangle_status);

   if (demangle_status != 0)
   {
      realname = ::strdup(function);
   }

   printf("0x%lx %s \t%s:%d\n", (unsigned long) pc,
          realname == nullptr ? "???" : realname,
          filename == nullptr ? "???" : filename, lineno);

   free(realname);

   return strcmp(function, "main") == 0 ? 1 : 0;
}


static void
error_callback(void *data, const char *msg, int errnum)
{
   printf("Something went wrong in libbacktrace: %s\n", msg);
}


///------
/** Print a demangled stack backtrace of the caller function to FILE* out. */
static inline void print_stacktrace(FILE *out = stderr, unsigned int max_frames = 63)
{
	   struct backtrace_state *lbstate;

	   printf ("Backtrace:\n");
	   lbstate = backtrace_create_state (nullptr, 1, error_callback, nullptr);
	   backtrace_full(lbstate, 0, full_callback, error_callback, 0);
}



#endif // _STACKTRACE_H_
