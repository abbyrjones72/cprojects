#include <stdio.h>

typedef struct _Rect_Dimensions
{
	double height;
	double width;
	double perimeter;
} Rect_Dimensions;

void calculate_rect_perimeter(Rect_Dimensions *pRD)
{
	pRD->height += 10.0;
	pRD->width += 10.0;
	pRD->perimeter = 2 * (pRD->height * pRD->width);
}

int main(void)
{
	Rect_Dimensions rd;
	rd.height = 15.0;
	rd.width = 22.5;
	calculate_rect_perimeter(&rd);
	return 0;
}

