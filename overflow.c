#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct commands {
	char input[10];
	char command[2];
};

int main() {
	struct commands a = {.input={0},.command="ls "};
	printf("File: ");
	gets(a.input);
	system(strcat(a.command,a.input));
}
