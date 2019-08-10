/* vim: expandtab:tw=68:ts=4:sw=4:
 *
 * error.h - Independent implementation of error(3) library.
 *           This library is commonly found in GNU/Linux systems.
 *
 * Copyright (c) 2005 Sudhi Herle <sw at herle.net>
 *
 * Licensing Terms: GPLv2
 *
 * If you need a commercial license for this work, please contact
 * the author.
 *
 * This software does not come with any express or implied
 * warranty; it is provided "as is". No claim  is made to its
 * suitability for any purpose.
 * Creation date: Sat Oct 15 22:15:16 2005
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <stdarg.h>
#include <errno.h>

/* Provide C linkage for symbols declared here .. */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Print an error message to stderr. If 'errnum' is non-zero, treat
 * it like 'errno.h:errno' and print the corresponding error string
 * (by calling strerror(3)). Lastly, if do_exit is non-zero, exit
 * the program (i.e., treat the error as fatal).
 */
extern void error(int do_exit, int errnum, const char *format, ...);

/*
 * if supplied, this function should print the name of the program
 * to stderr followed by a ':' and space.
 */
extern void (*error_print_progname) (void);

/*
 * if supplied, this variable should contain a string that
 * represents the name of the program.
 */
extern const char * program_name;


/*
 * Die with an error message.
 */
#if __STDC_VERSION__ >= 201112L // C11标准新增 _Noreturn 关键字
_Noreturn void die(const char *fmt, ...);
#else
__attribute__((noreturn)) void die(const char *fmt, ...);
#endif

/*
 * Show a warning.
 */
extern void warn(const char *fmt, ...);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ! ERROR_H_ */

/* EOF */
