#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    float x[2];
    if((fp = fopen("my-bin-file", "wb")) == 0)
    {
        fprintf(stderr, "Can't open file for writing.\n");
        return 1;
    }

    printf("Type two floating point numbers separated by a space: \n");
    scanf("%f %f", &x[0], &x[1]);

    /* fwrite(void *ptr, size_t size, size_t num_mem, FILE *stream) */
    fwrite(&x, sizeof(float), sizeof(x) / sizeof(float), fp);
    return 0;
}