#include "lexer.h"
#include "token.h"
#include <ctype.h> // isalnum()
#include <stdbool.h> // bool, false, true
#include <stddef.h> // size_t
#include <string.h> // strlen(), strncmp()


typedef struct s_token_spec
{
	const char   *lexeme;
	t_token_type type;
} t_token_spec;


static const t_token_spec g_token_keywords_table[] = {
	{"auto",     TOKEN_KW_AUTO},
	{"break",    TOKEN_KW_BREAK},
	{"case",     TOKEN_KW_CASE},
	{"char",     TOKEN_KW_CHAR},
	{"const",    TOKEN_KW_CONST},
	{"continue", TOKEN_KW_CONTINUE},
	{"default",  TOKEN_KW_DEFAULT},
	{"do",       TOKEN_KW_DO},
	{"double",   TOKEN_KW_DOUBLE},
	{"else",     TOKEN_KW_ELSE},
	{"enum",     TOKEN_KW_ENUM},
	{"extern",   TOKEN_KW_EXTERN},
	{"float",    TOKEN_KW_FLOAT},
	{"for",      TOKEN_KW_FOR},
	{"goto",     TOKEN_KW_GOTO},
	{"if",       TOKEN_KW_IF},
	{"int",      TOKEN_KW_INT},
	{"long",     TOKEN_KW_LONG},
	{"register", TOKEN_KW_REGISTER},
	{"return",   TOKEN_KW_RETURN},
	{"short",    TOKEN_KW_SHORT},
	{"signed",   TOKEN_KW_SIGNED},
	{"sizeof",   TOKEN_KW_SIZEOF},
	{"static",   TOKEN_KW_STATIC},
	{"struct",   TOKEN_KW_STRUCT},
	{"switch",   TOKEN_KW_SWITCH},
	{"typedef",  TOKEN_KW_TYPEDEF},
	{"union",    TOKEN_KW_UNION},
	{"unsigned", TOKEN_KW_UNSIGNED},
	{"void",     TOKEN_KW_VOID},
	{"volatile", TOKEN_KW_VOLATILE},
	{"while",    TOKEN_KW_WHILE},
};



static const t_token_spec g_token_operators_table[] = {
	/* 3-char Assignment Operators */
	{"<<=", TOKEN_OP_LSHIFT_ASSIGN},
	{">>=", TOKEN_OP_RSHIFT_ASSIGN},

	/* 2-char Special Operators */
	{"->", TOKEN_OP_ARROW},

	/* 2-char Unary Operators */
	{"++", TOKEN_OP_INCREMENT},
	{"--", TOKEN_OP_DECREMENT},

	/* 2-char Rational Operators */
	{"<=", TOKEN_OP_LEQ},
	{">=", TOKEN_OP_GEQ},
	{"==", TOKEN_OP_EQ},
	{"!=", TOKEN_OP_NEQ},

	/* 2-char Logical Operators */
	{"&&", TOKEN_OP_LOGICAL_AND},
	{"||", TOKEN_OP_LOGICAL_OR},

	/* 2-char Bitwise Operators */
	{"<<", TOKEN_OP_LSHIFT},
	{">>", TOKEN_OP_RSHIFT},

	/* 2-char Assignment Operators */
	{"+=", TOKEN_OP_ADD_ASSIGN},
	{"-=", TOKEN_OP_SUB_ASSIGN},
	{"*=", TOKEN_OP_MUL_ASSIGN},
	{"/=", TOKEN_OP_DIV_ASSIGN},
	{"&=", TOKEN_OP_AND_ASSIGN},
	{"|=", TOKEN_OP_OR_ASSIGN},
	{"~=", TOKEN_OP_INV_ASSIGN},
	{"^=", TOKEN_OP_XOR_ASSIGN},

	/* 1-char Arithmetic Operators */
	{"+", TOKEN_OP_ADD},
	{"-", TOKEN_OP_SUB},
	{"*", TOKEN_OP_MUL},
	{"/", TOKEN_OP_DIV},
	{"%", TOKEN_OP_MOD},

	/* 1-char Rational Operators */
	{"<", TOKEN_OP_LESS},
	{">", TOKEN_OP_GREATER},

	/* 1-char Logical Operators */
	{"!", TOKEN_OP_NOT},

	/* 1-char Bitwise Operators */
	{"&", TOKEN_OP_AND},
	{"|", TOKEN_OP_OR},
	{"~", TOKEN_OP_INV},
	{"^", TOKEN_OP_XOR},

	/* 1-char Assignment Operators */
	{"=", TOKEN_OP_ASSIGN},

	/* 1-char Ternary Operators */
	{"?", TOKEN_OP_QUESTION},
	{":", TOKEN_OP_COLON},
};


static const t_token_spec g_token_punctuators_table[] = {
	/* 3-char Punctuators */
	{"...", TOKEN_PUNC_ELLIPSIS},

	/* 1-char Punctuators */
	{"(", TOKEN_PUNC_LPAREN},
	{")", TOKEN_PUNC_RPAREN},
	{"{", TOKEN_PUNC_LBRACE},
	{"}", TOKEN_PUNC_RBRACE},
	{"[", TOKEN_PUNC_LBRACKET},
	{"]", TOKEN_PUNC_RBRACKET},
	{";", TOKEN_PUNC_SEMICOLON},
	{",", TOKEN_PUNC_COMMA},
	{".", TOKEN_PUNC_DOT},
};


static bool match_table(t_lexer *lx, t_token *tok, const t_token_spec *table, const size_t table_size)
{
	size_t i;
	size_t len;

	for (i = 0; i < table_size; i += 1) {
		len = strlen(table[i].lexeme);
		if (lx->pos + len > lx->len)
			continue;

		if ((strncmp(lx->src + lx->pos, table[i].lexeme, len) == 0)) {
			tok->start = lx->src + lx->pos;
			tok->len = len;
			tok->type = table[i].type;
			tok->line = lx->tok_line;
			tok->col = lx->tok_col;

			lexer_advance_n(lx, len);
			return (true);
		}
	}

	return (false);
}


void lex_keyword_or_identifier(t_lexer *lx, t_token *tok)
{
	size_t n;

	n = sizeof(g_token_keywords_table) / sizeof(g_token_keywords_table[0]);
	if (!match_table(lx, tok, g_token_keywords_table, n)) {
		while (isalnum((unsigned char)lexer_peek(lx)) || lexer_peek(lx) == '_')
		lexer_advance(lx, false);

		tok->start = lx->tok_start;
		tok->len   = (lx->src + lx->pos) - lx->tok_start;
		tok->line  = lx->tok_line;
		tok->col   = lx->tok_col;
		tok->type  = TOKEN_IDENTIFIER;
	}
}


void lex_number(t_lexer *lx, t_token *tok) //! Check error for 123abc or 123_ and special cases : binary and hexa ...
{
	while (isalnum((unsigned char)lexer_peek(lx)) || lexer_peek(lx) == '_')
		lexer_advance(lx, false);

	tok->start = lx->tok_start;
	tok->len   = (lx->src + lx->pos) - lx->tok_start;
	tok->line  = lx->tok_line;
	tok->col   = lx->tok_col;

	tok->type = TOKEN_LIT_INT;
}


void lex_operator_or_punctuator(t_lexer *lx, t_token *tok)
{
	size_t n;

	n = sizeof(g_token_operators_table) / sizeof(g_token_operators_table[0]);
	if (match_table(lx, tok, g_token_operators_table, n))
		return ;

	n = sizeof(g_token_punctuators_table) / sizeof(g_token_punctuators_table[0]);
	if (match_table(lx, tok, g_token_punctuators_table, n))
		return ;

	tok->start = lx->tok_start + lx->pos;
	tok->len   = 1;
	tok->type  = TOKEN_ERROR;
	tok->line  = lx->tok_line;
	tok->col   = lx->tok_col;

	lexer_advance(lx, false);
}
