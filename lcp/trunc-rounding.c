#include <stdio.h>

void double_func(double d);
void long_int_func(long int i);

int main(void)
{
	float float_value 	= 58.73;
	short int int_value	= 13;
	long_int_func(int_value);
	long_int_func(float_value);	/* possible truncation */

	double_func(float_value);
	double_func(int_value);

	return 0;
}

void double_func(double d)
{
	printf("double_func\t-> %.2f\n", d);
}

void long_int_func(long int i)
{
	printf("long_int_func\t-> %ld\n", i);
}
