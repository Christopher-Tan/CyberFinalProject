#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
	char a[] = {'t','e','s','t','\0','f','l','a','g','{','r','e','s','t','}','\0'};
	char b[492] = {0};
	read(STDIN_FILENO, b, 1000);
	printf(a);
}
