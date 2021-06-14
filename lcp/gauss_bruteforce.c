#include <stdio.h>
#include <stdbool.h>

int sum_brute_force(void);
int sum_brute_force_2();
int sum_n_via_gauss(void);

int main(void)
{
	int n = 100;
	printf("The sum of 1..100 = %d (via brute force)\n", sum_brute_force());
	printf("The sum of 1..100 = %d (via brute force 2)\n", sum_brute_force_2());
	printf("The sum of 1..%d = %d (via Gaussian insight)\n", sum_n_via_gauss());
	
	
	return 0;
}

int sum_brute_force()
{
	int result;
	for(int i = 1; i <= 100; i++)
	{
		result += i;
	}
	return result;
}

int sum_brute_force_2()
{
	int n = 1;
	int result;

	while(n <= 100)
	{
		result += n;
	}

	return result;
}
