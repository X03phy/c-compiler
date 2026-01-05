#include "compiler.h"
#include "colors.h"
#include <stdio.h> // FILE, 
#include <stdlib.h> // perror(), malloc(), free()

char *read_file(const char *path)
{
	FILE *fp;
	long filesize;
	char *buffer;
	size_t n;

	fp = fopen(path, "rb");
	if (fp == NULL) {
		fprintf(stderr, "Error while opening: %s\n", path);
		perror(path);
		return (NULL);
	}

	if (fseek(fp, 0, SEEK_END) != 0) {
		perror("fseek failed");
		fclose(fp);
		return (NULL);
	}

	filesize = ftell(fp);
	if (filesize < 0) {
		perror("ftell failed");
		fclose(fp);
		return (NULL);
	}

	rewind(fp);

	buffer = malloc(sizeof(char) * (filesize + 1));
	if (!buffer) {
		perror("malloc failed");
		fclose(fp);
		return (NULL);
	}

	n = fread(buffer, 1, filesize, fp);
	if (n != (size_t)filesize) {
		if (ferror(fp))
			perror("fread failed");
		else
			fprintf(stderr, "Incomplete file reading\n");
		free(buffer);
		fclose(fp);
		return (NULL);
	}

	buffer[filesize] = '\0';
	fclose(fp);

	return (buffer);
}
