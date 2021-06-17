#include <stdio.h>


double rect_perimeter(double *pH, double *pW)
{
	*pW += 10;
	*pW += 10;
	return 2 * (*pW + *pH);
}

int main(void)
{
	double height = 15.0;
	double width = 22.5;

	double* pHeight = &height;
	double* pWidth = &width;

	double perimeter = rect_perimeter(pHeight, pWidth);
	printf("%#lx\n", (unsigned long)(&perimeter));
	return 0;
}
