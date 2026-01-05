#include "compiler.h"
#include "colors.h"
#include <stdio.h> // fprintf(), stderr


int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, BOLDWHITE "%s: " RED "fatal error: " RESET "no input files\n", argv[0]);
		return (1);
	}

	compiler(argv[1]);

	return (0);
}
