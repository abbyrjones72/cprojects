#include <stdio.h>
#include <stdbool.h>

void print_logical_and(bool z, bool o);
void print_logical_or(bool z, bool o);
void print_logical_not(bool z, bool o);

int main() {
	bool one = 1;
	bool zero = 0;
	
	print_logical_and(zero, one);
	print_logical_or(zero, one);
	print_logical_not(zero, one);

}

void print_logical_and(bool z, bool o) {
	bool zero_zero 	= z && z;
	bool zero_one 	= z && o;
	bool one_zero	= o && z;
	bool one_one	= o && o;

	printf("AND | %1d | %1d\n", z, o);
	printf("  %1d | %1d | %1d\n", z, zero_zero, zero_one);
	printf("  %1d | %1d | %1d\n\n", o, zero_one, one_one);
}

void print_logical_or(bool z, bool o) {
	bool zero_zero 	= z || z;
	bool zero_one 	= z || o;
	bool one_zero	= o || z;
	bool one_one	= o || o;
	
	printf("OR | %1d | %1d\n", z, o);
	printf(" %1d | %1d | %1d\n", z, zero_zero, zero_one);
	printf(" %1d | %1d | %1d\n\n", o, zero_one, one_one);
}

void print_logical_not(bool z, bool o) {
	bool not_zero 	= !z;
	bool not_one 	= !o;
	
	printf("NOT\n");
	printf("  %1d | %1d\n", z, not_zero);
	printf("  %1d | %1d \n\n", o, not_one);
}
