#include "compiler.h"
#include "lexer.h"
#include <stdlib.h> // NULL, free()
#include "token.h"
#include "ast.h"


int compiler(const char *path)
{
	char *buffer = NULL;
	t_token_list *token_list = NULL;
	t_ast *tree = NULL;

	buffer = read_file(path);
	if (!buffer)
		return (1);

	token_list = lexer(buffer);
	if (!token_list) {
		free(buffer);
		return (1);
	}

	tree = parser(token_list);
	if (!tree) {
		token_list_free(&token_list);
		free(buffer);
		return (1);
	}

	print_token_list(token_list);
	print_ast(tree);

	token_list_free(&token_list);
	free(buffer);


	return (0);
}
