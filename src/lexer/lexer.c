#include "lexer.h"
#include "token.h"
#include <ctype.h> // isspace(), isalpha(), isdigit()
#include <stdio.h> // perror()
#include <stddef.h> // NULL


t_token lexer_next(t_lexer *lx)
{
	t_token tok;

	while (isspace((unsigned char)lexer_peek(lx)))
		lexer_advance(lx, false);

	if (lexer_peek(lx) == '\0') {
		tok.type = TOKEN_EOF;
		tok.start = lx->src + lx->pos;
		tok.len = 0;
		tok.line = lx->line;
		tok.col = lx->col;
		return (tok);
	}

	lexer_begin_token(lx);

	if (isalpha((unsigned char)lexer_peek(lx)) || lexer_peek(lx) == '_')
		lex_identifier_or_keyword(lx, &tok);
	else if (isdigit((unsigned char)lexer_peek(lx)))
		lex_number(lx, &tok);
	else
		lex_operator_or_punctuator(lx, &tok);

	return (tok);
}


t_token_list *lexer(const char *src)
{
	t_lexer lx;
	t_token tok;
	t_token_list *token_list = NULL;

	lexer_init(&lx, src);

	while (1)
	{
		tok = lexer_next(&lx);
		if (!token_list_push(&token_list, tok)) {
			token_list_free(&token_list);
			perror("malloc failed");
			return (NULL);
		}

		if (tok.type == TOKEN_EOF)
			break;
	}

	return (token_list);
}
