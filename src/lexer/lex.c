#include "lexer.h"
#include "token.h"
#include <ctype.h> // isalnum()
#include <stdbool.h> // false, true


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
	static const t_op ops = {}
	tok->start = lx->tok_start;
	tok->len   = (lx->src + lx->pos) - lx->tok_start;
	tok->line  = lx->tok_line;
	tok->col   = lx->tok_col;

	tok->type = TOKEN_PUNCTUATOR;
}
