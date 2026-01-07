#include "lexer.h"
#include "token.h"
#include <ctype.h> // isalnum()
#include <stdbool.h> // false, true
#include <stddef.h> // size_t
#include <string.h> // strlen(), strncmp()


typedef struct s_op
{
	const char   *str;
	t_token_type type;
} t_op;


static const t_op g_ops[] = { //! Change name -> plus precis
	/* 3-char Assignment Operator */
	{"<<=", TOKEN_LSHIFT_ASSIGN},
	{">>=", TOKEN_RSHIFT_ASSIGN},

	/* 3-char Punctuator */
	{"...", TOKEN_ELLIPSIS},

	/* 2-char Special Operator */
	{"->", TOKEN_ARROW},

	/* 2-char Unary Operator */
	{"++", TOKEN_INCREMENT},
	{"--", TOKEN_DECREMENT},

	/* 2-char Rational Operator */
	{"<=", TOKEN_LEQ},
	{">=", TOKEN_GEQ},
	{"==", TOKEN_EQ},
	{"!=", TOKEN_NEQ},

	/* 2-char Logical Operator */
	{"&&", TOKEN_LOGICAL_AND},
	{"||", TOKEN_LOGICAL_OR},

	/* 2-char Bitwise Operator */
	{"<<", TOKEN_LSHIFT},
	{">>", TOKEN_RSHIFT},

	/* 2-char Assignment Operator */
	{"+=", TOKEN_ADD_ASSIGN},
	{"-=", TOKEN_SUB_ASSIGN},
	{"*=", TOKEN_MUL_ASSIGN},
	{"/=", TOKEN_DIV_ASSIGN},
	{"&=", TOKEN_AND_ASSIGN},
	{"|=", TOKEN_OR_ASSIGN},
	{"~=", TOKEN_INV_ASSIGN},
	{"^=", TOKEN_XOR_ASSIGN},

	/* 1-char Arithmetic Operator */
	{"+", TOKEN_ADD},
	{"-", TOKEN_SUB},
	{"*", TOKEN_MUL},
	{"/", TOKEN_DIV},
	{"%", TOKEN_MOD},

	/* 1-char Rational Operator */
	{"<", TOKEN_LESS},
	{">", TOKEN_GREATER},

	/* 1-char Logical Operator */
	{"!", TOKEN_NOT},

	/* 1-char Bitwise Operator */
	{"&", TOKEN_AND},
	{"|", TOKEN_OR},
	{"~", TOKEN_INV},
	{"^", TOKEN_XOR},

	/* 1-char Assignment Operator */
	{"=", TOKEN_ASSIGN},

	/* 1-char Ternary Operator */
	{"?", TOKEN_QUESTION},
	{":", TOKEN_COLON},

	/* 1-char Punctuator */
	{"(", TOKEN_LPAREN},
	{")", TOKEN_RPAREN},
	{"{", TOKEN_LBRACE},
	{"}", TOKEN_RBRACE},
	{"[", TOKEN_LBRACKET},
	{"]", TOKEN_RBRACKET},
	{";", TOKEN_SEMICOLON},
	{",", TOKEN_COMMA},
	{".", TOKEN_DOT},
};


void lex_identifier_or_keyword(t_lexer *lx, t_token *tok)
{
	while (isalnum((unsigned char)lexer_peek(lx)) || lexer_peek(lx) == '_')
		lexer_advance(lx, false);

	tok->start = lx->tok_start;
	tok->len   = (lx->src + lx->pos) - lx->tok_start;
	tok->line  = lx->tok_line;
	tok->col   = lx->tok_col;

	if (is_keyword(tok->start, tok->len))
		tok->type = TOKEN_KEYWORD;
	else
		tok->type = TOKEN_IDENTIFIER;
}


void lex_number(t_lexer *lx, t_token *tok) //! Check error for 123abc or 123_ and special cases : binary and hexa ...
{
	while (isalnum((unsigned char)lexer_peek(lx)) || lexer_peek(lx) == '_')
		lexer_advance(lx, false);

	tok->start = lx->tok_start;
	tok->len   = (lx->src + lx->pos) - lx->tok_start;
	tok->line  = lx->tok_line;
	tok->col   = lx->tok_col;

	tok->type = TOKEN_INT;
}


void lex_operator_or_punctuator(t_lexer *lx, t_token *tok)
{
	size_t i;
	size_t len;

	for (i = 0; i < sizeof(g_ops) / sizeof(g_ops[0]); i += 1) {
		len = strlen(g_ops[i].str);
		if ((strncmp(lx->src + lx->pos, g_ops[i].str, len) == 0)) {
			tok->start = lx->src + lx->pos;
			tok->len = len;
			tok->type = g_ops[i].type;
			tok->line = lx->tok_line;
			tok->col = lx->tok_col;

			lexer_advance_n(lx, len);
			return ;
		}
	}

	tok->start = lx->tok_start + lx->pos;
	tok->len   = 1;
	tok->type  = TOKEN_INVALID;
	tok->line  = lx->tok_line;
	tok->col   = lx->tok_col;

	lexer_advance(lx, false);
}
