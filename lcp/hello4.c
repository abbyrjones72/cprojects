#include <stdio.h>

void print_comma() {
	printf(", ");
}

void print_word(char* word) {
	printf("%s", word);
}

void print_greeting(char* greeting, char* addressee) {
	print_word(greeting);
	print_comma();
	print_word(addressee);
	printf("!\n");
}

int main() {
	print_greeting("Hello", "world");
	print_greeting("Good day", "Your Royal Highness");
	print_greeting("Howdy", "John Q. and Jane P. Doe");
	print_greeting("Hey", "Moe, Larry, and Curly");

	return 0;
}



