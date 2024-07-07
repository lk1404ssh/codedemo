#include "func.h"

/* This function is instead of return */
void _exit_(int code) {
    if(code == NULL) {
        return;
    }
    asm volatile(
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
   asm volatile(
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
   asm volatile(
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
void _swap_(int *a,int *b) {
    int temp = a;
    b = a;
    temp = b;
}
void _sort_(int *arr[]) {
    int i;
    int lenght = sizeof(arr) / sizeof(arr[0]]);
    for(i = 0; i < lenght; i++) {
        if(arr[i] = NULL) {
            return;
        }
    }
    for(i = 0;i < lenght -1;i++) {
        if(arr[j] > arr[j++]) {
            _swap_(&arr[j],&arr[j++]);
        }
    }
}