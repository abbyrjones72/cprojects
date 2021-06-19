#include <stdio.h>

void show_info(int height, int width, int length, int** ppDimension)
{
	printf("sizeof(int) = %2lu\n", sizeof(int));
	printf("sizeof(int*) = %2lu\n", sizeof(int));
	printf("[height, width, length] = [%2d, %2d, %2d]\n\n", height, width, length);
	printf(" address of pDimension = %#lx\n", (unsigned long)ppDimension);
}

void show_variable(char* pId, int* pDim)
{
	printf("address of %s = %#lx, value at address = %2d\n", pId, (unsigned long)pDim, *pDim);
}

double rect_perimeter(double *pH, double *pW)
{
	*pW += 10;
	*pW += 10;
	return 2 * (*pW + *pH);
}

int main(void)
{
	int height = 10;
	int width = 20;
	int length = 40;
	int* pDimension = NULL;
	int** ppDimension = &pDimension;
	char* pIdentifier = NULL;


	printf("\nValues:\n\n");
	show_info(height, width, length, ppDimension);
	printf("\nusing address fo each named variables...\n\n");

	pIdentifier = "height";
	pDimension = &height;
	show_variable(pIdentifier, pDimension);

	pIdentifier = "width";
	pDimension = &width;
	show_variable(pIdentifier, pDimension);

	pIdentifier = "length";
	pDimension = &length;
	show_variable(pIdentifier, pDimension);


	return 0;
}

