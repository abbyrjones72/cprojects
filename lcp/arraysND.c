#include <stdio.h>
#include <stdbool.h>
#include "arraysND.h"

int main(void)
{
    const int size1D = 5;
    const int size2D = 4;
    const int size3D = 3;

    bool pretty = true;

    int array2D[size2D][size1D];
    int array3D[size3D][size2D][size1D];

    int total = 0;

    initialize2DArray(size2D, size1D, array2D);
    if(!pretty)
    {
        print2DArray(size2D, size1D, array2D);
    }
    else
    {
        pretty2DArray(size2D, size1D, array2D);
    }

    total = sum2DArray(size2D, size1D, array2D);
    printf("Total for array2D is %d\n\n", total);

    initialize3DArray(size3D, size2D, size1D, array3D);
    if(!pretty)
    {
        print3DArray(size3D, size2D, size1D, array3D);
    }
    else
    {
        pretty3DArray(size3D, size2D, size1D, array3D);
    }
    total = sum3DArray(size3D, size2D, size1D, array3D);
    printf("Total for 3Darray is %d\n\n", total);

}

void initialize2DArray(int row, int col, int array[row][col])
{
    for(int j = 0; j < row; j++)
    {
        for(int i = 0; i < col; i++)
        {
            array[j][i] = (10*j+1) + (i+1);
        }
    }
}

void initialize3DArray(int z, int y, int x, int array[z][y][x])
{
    for(int k = 0; k < z; k++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int i = 0; i < x; i++)
            {
                array[k][j][i] = (100*(k+1) + (10*j+1)) + (i+1);
            }
            
        }
    }
}

void printd2DArray(int row, int col, int array2D[row][col])
{
    for(int j = 0; j < row; j++)
    {
        for(int i = 0; i < col; i++)
        {
            printf("%4d", array2D[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void prettyPrint2DArray(int row, int col, int array[row][col])
{
    /* print column offsets as heading */
    printf("  ");
    for(int i = 0; i < row; i++)
    {
        printf(" [%1d]", i);
    }
    printf("\n");

    for(int j = 0; j < row; j++)
    {
        /* print row offset as lead in */
        printf("[%1d]", j);

        for(int i = 0; i < col; i++)
        {
            printf("%4d", array[j][i]);
        }
    }
}

void printd3DArray(int z, int y, int x, int array[z][y][x])
{
    for(int k = 0; k < z; k++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int i = 0; i < x; i++)
            {
                printf("%4d", array[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void prettyPrint3DArray(int z, int y, int x, int array[z][y][x])
{
    for(int k = 0; k < z; k++)
    {
        /* print z offset as lead-in */
        printf("[%1d]", k);

        /* print x offset heading */
        printf("   ");

        for(int i = 0; i < x; i++)
        {
            printf("\n");
        }

        for(int j = 0; j < y; j++)  /* j : 0..(y-1) */
        {
            /* print y offset as lead-in */
            printf("    [%1d]", j);
            for(int i = 0; i < x; i++)
            {
                printf("%4d", array[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int sum2DArray(int row, int col, int array[row][col])
{
    int sum = 0;
    for(int j = 0; j < row; j++)
    {
        for(int i = 0; i < col; i++)
        {
            sum += array[j][i];
        }
    }
    return sum;
}

int sum3DArray(int z, int y, int x, int array[z][y][x])
{
    int sum = 0;
    for(int k = 0; k < z; k++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int i = 0; i < x; i++)
            {
                sum += array[k][j][i];
            }
        }
    }
    return sum;
}