#include <stdio.h>

int main(void)
{
	int a_value = 5;

	/* demonstrate prefix incrementation */
	printf("Initial: %d\n", a_value);
	printf("Prefix: %d\n", ++a_value);
	printf("Current value: %d\n", a_value);

	/* demonstrate postfix incrementation */
	printf("Inital: %d\n", a_value);
	printf("Postfix: %d\n", a_value++);
	printf("Current value: %d\n", a_value);

	/* incrementation in isolation (more predictable outcomes */
	a_value = 5;
	++a_value;
	printf("++a_value (alone) == %d\n", a_value);
	a_value = 5;
	printf("a_value++ (alone) == %d\n", a_value);

	return 0;
}
