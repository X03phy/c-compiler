#include "lexer.h"


int main(int argc, char **argv)
{
	FILE *fp;
	long filesize;
	char *buffer;
	size_t n;
	t_token_list *token_list;

	if (argc != 2) {
		fprintf(stderr, BOLDWHITE "%s: " RED "fatal error: " RESET "no input files\n", argv[0]);
		return (1);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "Error while opening: %s\n", argv[1]);
		perror(argv[1]);
		return (1);
	}

	if (fseek(fp, 0, SEEK_END) != 0) {
		perror("fseek failed");
		fclose(fp);
		return (1);
	}

	filesize = ftell(fp);
	if (filesize < 0) {
		perror("ftell failed");
		fclose(fp);
		return (1);
	}

	rewind(fp);

	buffer = malloc(sizeof(char) * (filesize + 1));
	if (!buffer) {
		perror("malloc failed");
		fclose(fp);
		return (1);
	}

	n = fread(buffer, 1, filesize, fp);
	if (n != (size_t)filesize) {
		if (ferror(fp))
			perror("fread failed");
		else
			fprintf(stderr, "Incomplete file reading\n");
		free(buffer);
		fclose(fp);
		return (1);
	}

	buffer[filesize] = '\0';
	fclose(fp);

	token_list = lexer(buffer);
	if (!token_list) {
		free(buffer);
		return (1);
	}

	print_token_list(token_list, buffer);
	token_list_free(&token_list);

	free(buffer);

	return (0);
}
