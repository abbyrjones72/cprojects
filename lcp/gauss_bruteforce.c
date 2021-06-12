#include <stdio.h>
#include <stdbool.h>

int sum_brute_force(void);
int sum_brute_force_2(void);
int sum_n_via_gauss(void);

int main(void)
{
	int n = 100;
	printf("The sum of 1..100 = %d (via brute force)\n", sum_brute_force());
	printf("The sum of 1..100 = %d (via brute force 2)\n", sum_brute_force_2());
	printf("The sum of 1..%d = %d (via Gaussian insight)\n", sum_n_via_gauss());
	
	
	return 0;
}
