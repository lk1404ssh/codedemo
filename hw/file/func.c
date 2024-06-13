#include "func.h"

/* This function is instead of return */
void _exit_(int code) {
    if(code == NULL) {
        return;
    }
    _asm__volatile_(
        "movl $1,%%eax\n\t"
        "movl %0,%%ebx\n\t"
        "int $0x80"
        :
        : "=r" (code)
        : "%eax","%ebx"
    );
}
/* This just a simple edition */
void _put_(const char *str) {
   if(*str == NULL) {
        return;
   }
   int lenght;
   /* Get string lenght */
   while(*str != '\0') {
        lenght++;
        *str++;
   }
   _asm__volatile_(
        "movl $4,%%eax\n"
        "movl $1,%%ebx\n"
        "movl %0,%%ecx\n"
        "movl %1,%%edx\n"
        "int $0x80"
        :
        : "r" (str)
        : "=r" (lenght)
   );
}
void _put_error_(const char *str) {
   if(str == NULL) {
        return;
   }
   int lenght;
   while(*str != '\0') {
        lenght++;
        *str++;
   }
   _asm__volatile_(
        "movl $4,%%eax\n"
        "movl $2,%%ebx\n"
        "movl %0,%%ecx\n"
        "movl %1,%%edx\n"
        "int $0x80"
        :
        : "r" (str)
        : "=r" (lenght)
   );
}
/* This just simple scanf function only */
void _get_(char *buffer) {
    _asm__volatile(
        "movl $3,%%eax\n\t"
        "movl $0,%%ebx\n\t"
        "movl %0,%%ecx\n\t"
        "movl %1,%%edx\n\t"
        "int $0x80"
        :
        : "r" (buffer)
        : "=r" (int)sizeof(buffer) / sizeof(buffer[0])
    );
}