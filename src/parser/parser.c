#include "parser.h"
#include "ast.h"
#include "token.h"
#include <stddef.h> // NULL


t_ast *parser(t_token_list *token_list)
{
	t_ast *tree = NULL;
	t_token token;

	if (!token_list)
		return (NULL);

	while (1) {
		token = token_list->token;

		if (token.type == TOKEN_EOF)
			break;

		if ()
		token_list = token_list->next;
	}

	return (tree);
}
