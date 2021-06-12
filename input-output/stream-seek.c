#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch; /* for each character in the stream */
    FILE *fp;
    if(argc < 3 || argc > 4)
    {
        fprintf(stderr, "Usage: %s [path] [from position] [to position]\n", argv[0]);
        return 1;
    }

    /* open file with read mode */
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("cannot open file for reading.");
        return 1;
    }

    fseek(fp, atoi(argv[2]), SEEK_SET);

    /* loop over each line and write it out to stdout */
    while((ch = fgetc(fp)) != EOF)
    {
        /* we are making sure the user entered a 'to position' value */
        if(argv[3] != NULL) 
        {
            /* here, ftell returns the current value of the file pos indicator 
                so we are checking to make sure it is not >= the third arg, which is 
                the 'to position' in the usage statement */
            if(ftell(fp) >= atoi(argv[3]))
            {
                break;
            }
        }
        putchar(ch);
    }

    printf("\n");
    fclose(fp);

    return 0;
}
