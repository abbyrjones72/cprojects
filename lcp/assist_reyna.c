#include <stdio.h>

void grade_student(int);

int main()
{
	
	int grade = 0;
	
	printf("Enter Grade:\n");
	scanf("%d", &grade);
	grade_student(grade);

	return 0;
}

void grade_student(int mark) 
{
	switch(mark / 10)
	{
		
		case 10:
		case 9:
			printf("Grade: A\n");
			break;
		case 8:
			printf("Grade: B\n");
			break;
		case 7:
			printf("Grade: C\n");
			break;
		case 6:
			printf("Grade: D\n");
			break;
		default:
			printf("Grade: F\n");
			break;

	}
}
