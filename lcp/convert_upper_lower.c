#include <stdio.h>

int main(void) {
	char lower_char = 'b';
	char upper_char = 'M';

	char an_upper = lower_char - 32;
	char a_lower = upper_char + 32;

	printf("Lower case %c can be changed to upper case %c\n", lower_char, an_upper);
	printf("Upper case %c can be changed to lower case %c\n", upper_char, a_lower);
	
}
