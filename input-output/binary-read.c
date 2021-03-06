#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    float x[2];
    if((fp = fopen("my-bin-file", "rb")) == NULL)
    {
        fprintf(stderr, "Cannot open file for reading.\n");
        return 1;
    }

    /* exactly the same args as fwrite() 
        see: binary_write.c */
    fread(&x, sizeof(float), sizeof(x) / sizeof(float), fp);
    printf("The first number was: %f\n", x[0]);
    printf("The second number was: %f\n", x[1]);
    fclose(fp);
    
    return 0;
}