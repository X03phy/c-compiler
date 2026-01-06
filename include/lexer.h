#ifndef LEXER_H
#define LEXER_H


/*
 * Includes
*/
#include <stddef.h> // size_t
#include <stdbool.h> // bool
#include "token.h" // token types and functions


/*
 * Structures
*/
typedef struct s_lexer
{
	const char *src;
	size_t     pos;
	size_t     len;

	size_t     line;
	size_t     col;

	const char *tok_start;
	size_t     tok_line;
	size_t     tok_col;
} t_lexer;


/*
 * Prototypes
*/
// utils.c
void lexer_init(t_lexer *lx, const char *src);
char lexer_advance(t_lexer *lx, bool str);
void lexer_advance_n(t_lexer *lx, size_t n);
char lexer_peek(t_lexer *lx);
void lexer_begin_token(t_lexer *lx);

// check.c
bool is_keyword(const char *start, size_t len);

// lex.c
void lex_identifier_or_keyword(t_lexer *lx, t_token *tok);
void lex_number(t_lexer *lx, t_token *tok);
void lex_operator_or_punctuator(t_lexer *lx, t_token *tok);

// lexer.c
t_token lexer_next(t_lexer *lx);
t_token_list *lexer(const char *str);


#endif
