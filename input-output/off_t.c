#include <stdio.h>
#include <sys/types.h>

int main()
{
    printf("%lu bytes is the size of off_t\n", sizeof(off_t));
    return 0;
}