#include "token.h"
#include "colors.h"
#include <stddef.h> // size_t
#include <stdio.h> // printf()


static const char *g_token_type_name[] = {
	[TOKEN_EOF]           = "EOF",
	[TOKEN_ERROR]         = "ERROR",

	/* Identifiers & literals */
	[TOKEN_KW_AUTO] = "AUTO",
	[TOKEN_KW_BREAK] = "BREAK",
	[TOKEN_KW_CASE] = "CASE",
	[TOKEN_KW_CHAR] = "CHAR",
	[TOKEN_KW_CONST] = "CONST",
	[TOKEN_KW_CONTINUE] = "CONTINUE",
	[TOKEN_KW_DEFAULT] = "DEFAULT",
	[TOKEN_KW_DO] = "DO",
	[TOKEN_KW_DOUBLE] = "DOUBLE",
	[TOKEN_KW_ELSE] = "ELSE",
	[TOKEN_KW_ENUM] = "ENUM",
	[TOKEN_KW_EXTERN] = "EXTERN",
	[TOKEN_KW_FLOAT] = "FLOAT",
	[TOKEN_KW_FOR] = "FOR",
	[TOKEN_KW_GOTO] = "GOTO",
	[TOKEN_KW_IF] = "IF",
	[TOKEN_KW_INT] = "INT",
	[TOKEN_KW_LONG] = "LONG",
	[TOKEN_KW_REGISTER] = "REGISTER",
	[TOKEN_KW_RETURN] = "RETURN",
	[TOKEN_KW_SHORT] = "SHORT",
	[TOKEN_KW_SIGNED] = "SIGNED",
	[TOKEN_KW_SIZEOF] = "SIZEOF",
	[TOKEN_KW_STATIC] = "STATIC",
	[TOKEN_KW_STRUCT] = "STRUCT",
	[TOKEN_KW_SWITCH] = "SWITCH",
	[TOKEN_KW_TYPEDEF] = "TYPEDEF",
	[TOKEN_KW_UNION] = "UNION",
	[TOKEN_KW_UNSIGNED] = "UNSIGNED",
	[TOKEN_KW_VOID] = "VOID",
	[TOKEN_KW_VOLATILE] = "VOLATIE",
	[TOKEN_KW_WHILE] = "WHILE",

	[TOKEN_IDENTIFIER]    = "IDENTIFIER",
	[TOKEN_LIT_INT]           = "INT",
	[TOKEN_LIT_FLOAT]         = "FLOAT",
	[TOKEN_LIT_CHAR]          = "CHAR",
	[TOKEN_LIT_STRING]        = "STRING",

	/* Assignment operators */
	[TOKEN_OP_ASSIGN]        = "=",
	[TOKEN_OP_ADD_ASSIGN]    = "+=",
	[TOKEN_OP_SUB_ASSIGN]    = "-=",
	[TOKEN_OP_MUL_ASSIGN]    = "*=",
	[TOKEN_OP_DIV_ASSIGN]    = "/=",
	[TOKEN_OP_AND_ASSIGN]    = "&=",
	[TOKEN_OP_OR_ASSIGN]     = "|=",
	[TOKEN_OP_XOR_ASSIGN]    = "^=",
	[TOKEN_OP_INV_ASSIGN]    = "~=",
	[TOKEN_OP_LSHIFT_ASSIGN] = "<<=",
	[TOKEN_OP_RSHIFT_ASSIGN] = ">>=",

	/* Arithmetic operators */
	[TOKEN_OP_ADD]           = "+",
	[TOKEN_OP_SUB]           = "-",
	[TOKEN_OP_MUL]           = "*",
	[TOKEN_OP_DIV]           = "/",
	[TOKEN_OP_MOD]           = "%",

	/* Comparison operators */
	[TOKEN_OP_LESS]          = "<",
	[TOKEN_OP_GREATER]       = ">",
	[TOKEN_OP_LEQ]           = "<=",
	[TOKEN_OP_GEQ]           = ">=",
	[TOKEN_OP_EQ]            = "==",
	[TOKEN_OP_NEQ]           = "!=",

	/* Logical operators */
	[TOKEN_OP_LOGICAL_AND]   = "&&",
	[TOKEN_OP_LOGICAL_OR]    = "||",
	[TOKEN_OP_NOT]           = "!",

	/* Bitwise operators */
	[TOKEN_OP_AND]           = "&",
	[TOKEN_OP_OR]            = "|",
	[TOKEN_OP_XOR]           = "^",
	[TOKEN_OP_INV]           = "~",
	[TOKEN_OP_LSHIFT]        = "<<",
	[TOKEN_OP_RSHIFT]        = ">>",

	/* Unary / special */
	[TOKEN_OP_INCREMENT]     = "++",
	[TOKEN_OP_DECREMENT]     = "--",
	[TOKEN_OP_ARROW]         = "->",

	/* Ternary */
	[TOKEN_OP_QUESTION]      = "?",
	[TOKEN_OP_COLON]         = ":",

	/* Punctuators */
	[TOKEN_PUNC_LPAREN]        = "(",
	[TOKEN_PUNC_RPAREN]        = ")",
	[TOKEN_PUNC_LBRACE]        = "{",
	[TOKEN_PUNC_RBRACE]        = "}",
	[TOKEN_PUNC_LBRACKET]      = "[",
	[TOKEN_PUNC_RBRACKET]      = "]",
	[TOKEN_PUNC_SEMICOLON]     = ";",
	[TOKEN_PUNC_COMMA]         = ",",
	[TOKEN_PUNC_DOT]           = ".",
	[TOKEN_PUNC_ELLIPSIS]      = "...",
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
