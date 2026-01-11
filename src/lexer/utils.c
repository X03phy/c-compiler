#include "lexer.h"
#include <string.h> // strlen()
#include <stdbool.h> // bool, true


void lexer_init(t_lexer *lx, const char *src)
{
	lx->src = src;
	lx->len = strlen(src);
	lx->pos = 0;
	lx->line = 1;
	lx->col = 1;
}


char lexer_advance(t_lexer *lx, bool in_string)
{
	char c;

	if (lx->pos >= lx->len)
		return ('\0');

	c = lx->src[++lx->pos];

	if (!in_string && c == '\n') {
		lx->line += 1;
		lx->col = 1;
	} else {
		lx->col += 1;
	}

	return c;
}


void lexer_advance_n(t_lexer *lx, size_t n)
{
	size_t i;

	for (i = 0; i < n; i += 1)
		lexer_advance(lx, false);
}


char lexer_peek(t_lexer *lx)
{
	if (lx->pos >= lx->len)
		return '\0';
	return lx->src[lx->pos];
}


void lexer_begin_token(t_lexer *lx)
{
	lx->tok_start = lx->src + lx->pos;
	lx->tok_line = lx->line;
	lx->tok_col = lx->col;
}
