#include "token.h"
#include "colors.h"
#include <stddef.h> // size_t
#include <stdio.h> // printf()


static const char *g_token_type_name[] = {
	[TOKEN_EOF]           = "EOF",
	[TOKEN_INVALID]       = "INVALID",

	/* Identifiers & literals */
	[TOKEN_KEYWORD]       = "KEYWORD",
	[TOKEN_IDENTIFIER]    = "IDENTIFIER",
	[TOKEN_INT]           = "INT",
	[TOKEN_FLOAT]         = "FLOAT",
	[TOKEN_CHAR]          = "CHAR",
	[TOKEN_STRING]        = "STRING",

	/* Assignment operators */
	[TOKEN_ASSIGN]        = "=",
	[TOKEN_ADD_ASSIGN]    = "+=",
	[TOKEN_SUB_ASSIGN]    = "-=",
	[TOKEN_MUL_ASSIGN]    = "*=",
	[TOKEN_DIV_ASSIGN]    = "/=",
	[TOKEN_AND_ASSIGN]    = "&=",
	[TOKEN_OR_ASSIGN]     = "|=",
	[TOKEN_XOR_ASSIGN]    = "^=",
	[TOKEN_INV_ASSIGN]    = "~=",
	[TOKEN_LSHIFT_ASSIGN] = "<<=",
	[TOKEN_RSHIFT_ASSIGN] = ">>=",

	/* Arithmetic operators */
	[TOKEN_ADD]           = "+",
	[TOKEN_SUB]           = "-",
	[TOKEN_MUL]           = "*",
	[TOKEN_DIV]           = "/",
	[TOKEN_MOD]           = "%",

	/* Comparison operators */
	[TOKEN_LESS]          = "<",
	[TOKEN_GREATER]       = ">",
	[TOKEN_LEQ]           = "<=",
	[TOKEN_GEQ]           = ">=",
	[TOKEN_EQ]            = "==",
	[TOKEN_NEQ]           = "!=",

	/* Logical operators */
	[TOKEN_LOGICAL_AND]   = "&&",
	[TOKEN_LOGICAL_OR]    = "||",
	[TOKEN_NOT]           = "!",

	/* Bitwise operators */
	[TOKEN_AND]           = "&",
	[TOKEN_OR]            = "|",
	[TOKEN_XOR]           = "^",
	[TOKEN_INV]           = "~",
	[TOKEN_LSHIFT]        = "<<",
	[TOKEN_RSHIFT]        = ">>",

	/* Unary / special */
	[TOKEN_INCREMENT]     = "++",
	[TOKEN_DECREMENT]     = "--",
	[TOKEN_ARROW]         = "->",

	/* Ternary */
	[TOKEN_QUESTION]      = "?",
	[TOKEN_COLON]         = ":",

	/* Punctuators */
	[TOKEN_LPAREN]        = "(",
	[TOKEN_RPAREN]        = ")",
	[TOKEN_LBRACE]        = "{",
	[TOKEN_RBRACE]        = "}",
	[TOKEN_LBRACKET]      = "[",
	[TOKEN_RBRACKET]      = "]",
	[TOKEN_SEMICOLON]     = ";",
	[TOKEN_COMMA]         = ",",
	[TOKEN_DOT]           = ".",
	[TOKEN_ELLIPSIS]      = "...",
};


void print_token_list(t_token_list *lst)
{
	size_t i = 0;

	while (lst) {
		const char *type_name = "UNKNOWN";

		if (lst->token.type < sizeof(g_token_type_name) / sizeof(*g_token_type_name)
			&& g_token_type_name[lst->token.type])
			type_name = g_token_type_name[lst->token.type];

		printf(
			GREEN "token %zu:" RESET
			" value: '" YELLOW "%.*s" RESET "'"
			" type: " BLUE "%s\n" RESET,
			i,
			(int)lst->token.len,
			lst->token.start,
			type_name
		);

		lst = lst->next;
		i++;
	}
}
