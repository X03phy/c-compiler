#include "token.h"
#include "colors.h"
#include <stdio.h> // printf()


void print_token_list(t_token_list *tok_lst, const char *src)
{
	static const char *token_type_name[] = {
		[TOKEN_EOF]        = "EOF",
		[TOKEN_ERROR]      = "ERROR",
		[TOKEN_KEYWORD]    = "KEYWORD",
		[TOKEN_IDENTIFIER] = "IDENTIFIER",
		[TOKEN_CONSTANT]   = "CONSTANT",
		[TOKEN_STRING]     = "STRING",
		[TOKEN_OPERATOR]   = "OPERATOR",
		[TOKEN_PUNCTUATOR] = "PUNCTUATOR"
	};
	int i = 0;

	(void)src;
	while (tok_lst) {
		printf(GREEN "token %d:" RED " value: '%.*s'" BLUE " type: %s\n" RESET,
		       i,
		       (int)tok_lst->token.len, tok_lst->token.start,
		       token_type_name[tok_lst->token.type]
		      );
		tok_lst = tok_lst->next;
		i += 1;
	}
}
