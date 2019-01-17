#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av) {
	char *ptr;

	ptr = getenv(av[1]);
	printf("%s will be at %p\n", av[1], ptr);
}
