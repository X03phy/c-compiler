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


static const t_op g_ops[] = {
	/* multi-char operators */
	{"<<=", TOKEN_OPERATOR},
	{">>=", TOKEN_OPERATOR},
	{"++",  TOKEN_OPERATOR},
	{"--",  TOKEN_OPERATOR},
	{"->",  TOKEN_OPERATOR},
	{"+=",  TOKEN_OPERATOR},
	{"-=",  TOKEN_OPERATOR},
	{"*=",  TOKEN_OPERATOR},
	{"/=",  TOKEN_OPERATOR},
	{"==",  TOKEN_OPERATOR},
	{"!=",  TOKEN_OPERATOR},
	{"<=",  TOKEN_OPERATOR},
	{">=",  TOKEN_OPERATOR},
	{"&&",  TOKEN_OPERATOR},
	{"||",  TOKEN_OPERATOR},

	/* 1-char operators */
	{"+", TOKEN_OPERATOR},
	{"-", TOKEN_OPERATOR},
	{"*", TOKEN_OPERATOR},
	{"/", TOKEN_OPERATOR},
	{"%", TOKEN_OPERATOR},
	{"=", TOKEN_OPERATOR},
	{"<", TOKEN_OPERATOR},
	{">", TOKEN_OPERATOR},
	{"!", TOKEN_OPERATOR},
	{"&", TOKEN_OPERATOR},
	{"|", TOKEN_OPERATOR},
	{"^", TOKEN_OPERATOR},
	{"~", TOKEN_OPERATOR},
	{"?", TOKEN_OPERATOR},
	{":", TOKEN_OPERATOR},

	/* punctuators */
	{"(", TOKEN_PUNCTUATOR},
	{")", TOKEN_PUNCTUATOR},
	{"{", TOKEN_PUNCTUATOR},
	{"}", TOKEN_PUNCTUATOR},
	{"[", TOKEN_PUNCTUATOR},
	{"]", TOKEN_PUNCTUATOR},
	{";", TOKEN_PUNCTUATOR},
	{",", TOKEN_PUNCTUATOR},
	{".", TOKEN_PUNCTUATOR},
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


void lex_number(t_lexer *lx, t_token *tok)
{
	while (isalnum((unsigned char)lexer_peek(lx)) || lexer_peek(lx) == '_')
		lexer_advance(lx, false);

	tok->start = lx->tok_start;
	tok->len   = (lx->src + lx->pos) - lx->tok_start;
	tok->line  = lx->tok_line;
	tok->col   = lx->tok_col;

	tok->type = TOKEN_CONSTANT;
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
