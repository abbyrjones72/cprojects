#include <stdio.h>
#include <stdlb.h>

int main()
{
    int i;
    clrscr();
    printf("Making sound....");

    for(i = 0; i < 100; i++)
    {
        sound(250 * i);
        delay(250);
        nosound();
    }
    return 0;
}