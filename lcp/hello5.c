#include <stdio.h>

void print_greeting(char* greeting, char* addressee) {
	printf("%s, %s\n", greeting, addressee);
}

int main() {
	print_greeting("Hello", "world");
	print_greeting("Good day", "Your Royal Highness");
	print_greeting("Howdy", "John Q. and Jane P. Doe");
	print_greeting("Hey", "Moe, Larry, and Curly");

	return 0;
}



