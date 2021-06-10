#include <stdio.h>

int main(void) {
	char digit5 = '5';
	char digit8 = '8';

	int sum_digits = digit5 + digit8;
	printf("digit5 + digit8 = '5' + '8' = %d // adding ascii values)\n", sum_digits);

	char value5 = digit5 - '0'; // implicit conversion to int
	char value8 = digit8 - '0'; // implicit conversion to int

	sum_digits = value5 + value8;
	printf("value5 + value8 = %d\n", sum_digits);
}
