#include <stdio.h>

int main(void)
{
    int height = 10;
    int width = 20;
    int length = 40;
    int* p_dimension;

    printf("sizeof(int) = %2lu\n", sizeof(int));
    printf("sizeof(int*) = %2lu\n", sizeof(int*));
    printf("[height, width, length] = [%2d, %2d, %2d]\n", height, width, length);
    printf("address of p_dimension = %#lx\n\n", (unsigned long)p_dimension);

printf("Using address of each of the named variables...\n");
    p_dimension = &height;
    printf("address of height = %#lx, value at address = %2d\n", (unsigned long)p_dimension, *p_dimension);

    p_dimension = &width;
    printf("address of width = %#lx, value at address = %2d\n", (unsigned long)p_dimension, *p_dimension);

    p_dimension = &length;
    printf("address of length = %#lx, value at address = %2d\n", (unsigned long)p_dimension, *p_dimension);

    return 0;
}