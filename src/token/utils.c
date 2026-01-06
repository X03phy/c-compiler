#include "token.h"
#include "colors.h"
#include <stddef.h> // size_t
#include <stdio.h> // printf()


void print_token_list(t_token_list *tok_lst, const char *src)
{
	static const char *token_type_name[] = {
		[TOKEN_EOF]        = "EOF",
		[TOKEN_INVALID]    = "INVALID",
		[TOKEN_KEYWORD]    = "KEYWORD",
		[TOKEN_IDENTIFIER] = "IDENTIFIER",
		[TOKEN_INT]        = "INT",
		[TOKEN_FLOAT]      = "FLOAT",
		[TOKEN_CHAR]       = "CHAR",
		[TOKEN_STRING]     = "STRING",
		[TOKEN_OPERATOR]   = "OPERATOR",
		[TOKEN_PUNCTUATOR] = "PUNCTUATOR"
	};
	size_t i = 0;

	(void)src;
	while (tok_lst) {
		printf(GREEN "token %zu:" RED " value: '%.*s'" BLUE " type: %s\n" RESET,
		       i,
		       (int)tok_lst->token.len, tok_lst->token.start, //! Check doc
		       token_type_name[tok_lst->token.type]
		      );
		tok_lst = tok_lst->next;
		i += 1;
	}
}
