/* func.h
 * Because I am not have stdio.h
 * So I write this header
 * Have printf(simple) and return
 * Althought I not have stdio.h
 * But I also have assembly
 * (C) 2024 Bob Adlis
*/
#define NULL ((void)*0)
#define FUNC_H
#ifdef FUNC_H
extern void _exit_(int code);
extern void _put_(const char *str);
extern void _put_error_(const char *str);
extern void _get_(char *buffer);
#endif