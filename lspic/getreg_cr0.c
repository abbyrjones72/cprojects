/* 
REGISTERS:
    There are six control registers in the x86_64 chipset:
    -> CR0 - CR4,
    -> CR8

    CR0 can:
        -> turn hardware paging on and off
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef unsigned long u64;

/* this will cause a segmentation fault because cr0 has supervisor privilege
    requirement, trying to move user-space data to the kernel-space */
static u64 getreg_cr0(void) {
    __asm__ __volatile__("movq %cr0, %rax"); // this is AT&Ts method for inline assembly
}

int main(void) {
    printf("Hello, inline assembly:\n [RCX] = 0x%lx\n", getreg_cr0());
    exit(0);
}
