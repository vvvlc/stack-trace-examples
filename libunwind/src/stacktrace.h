// stacktrace.h (c) 2008, Timo Bingmann from http://idlebox.net/
// published under the WTFPL v2.0

#ifndef _STACKTRACE_H_
#define _STACKTRACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include <string.h>
#include <libunwind.h>

char **gargv;

int getFileAndLine (unw_word_t addr, char *file, size_t flen, int *line)
{
        static char buf[256];

        // prepare command to be executed
        // our program need to be passed after the -e parameter, 0x555555554000L is a first address from from cat /proc/pid/maps | grep r-xp, see troubleshooting
        sprintf (buf, "/usr/bin/addr2line -C -e %s -f -i %lx", gargv[0],(unsigned long) addr-0x555555554000L);
        FILE* f = popen (buf, "r");

        if (f == NULL)
        {
                perror (buf);
                return 0;
        }

        // get function name
        fgets (buf, 256, f);

        // get file and line
        fgets (buf, 256, f);

        if (buf[0] != '?')
        {
                char *p = buf;

                // file name is until ':'
                while (*p != ':')
                {
                        p++;
                }

                *p++ = 0;
                // after file name follows line number
                strcpy (file , buf);
                sscanf (p,"%d", line);
        }
        else
        {
                strcpy (file,"unkown");
                *line = 0;
        }

        pclose(f);
        return 1;
}


///------
/** Print a demangled stack backtrace of the caller function to FILE* out. */
static inline void print_stacktrace(FILE *out = stderr, unsigned int max_frames = 63)
{
    char name[256];
    unw_cursor_t cursor; unw_context_t uc;
    unw_word_t ip, sp, offp;

    unw_getcontext(&uc);
    unw_init_local(&cursor, &uc);

    while (unw_step(&cursor) > 0)
    {
            char file[256];
            int line = 0;

            name[0] = '\0';
            unw_get_proc_name(&cursor, name, 256, &offp);
            unw_get_reg(&cursor, UNW_REG_IP, &ip);
            unw_get_reg(&cursor, UNW_REG_SP, &sp);

            //printf ("%s ip = %lx, sp = %lx\n", name, (long) ip, (long) sp);
            getFileAndLine((long)ip, file, 256, &line);
            printf("%s in file %s line %d\n", name, file, line);
    }
}



#endif // _STACKTRACE_H_
