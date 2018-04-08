// stacktrace.h (c) 2008, Timo Bingmann from http://idlebox.net/
// published under the WTFPL v2.0

#ifndef _STACKTRACE_H_
#define _STACKTRACE_H_

#define BACKWARD_HAS_DW 1
#include "backward.hpp"


///------
/** Print a demangled stack backtrace of the caller function to FILE* out. */
static inline void print_stacktrace(FILE *out = stderr, unsigned int max_frames = 63)
{
	/*
	using namespace backward;
	StackTrace st; st.load_here(32);
	Printer p; p.print(st);
	*/
	using namespace backward;
	StackTrace st; st.load_here(32);
	Printer p;
	p.object = true;
	p.color_mode = ColorMode::always;
	p.address = true;
	p.print(st, stderr);
}



#endif // _STACKTRACE_H_
