#include "compiler.h"
#include "lexer.h"
#include "token.h"
#include <stdlib.h> // free()


int compiler(const char *path)
{
	char *buffer = NULL;
	t_token_list *token_list = NULL;

	buffer = read_file(path);
	if (!buffer)
		return (1);

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
