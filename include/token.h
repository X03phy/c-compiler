#ifndef TOKEN_H
#define TOKEN_H


/*
 * Includes
*/
#include <stddef.h> // size_t


/*
 * Enums
*/
typedef enum e_token_type {
	TOKEN_EOF, //! Pas sur de le garder, peut etre remplace par null dans les checks
	TOKEN_INVALID,

	TOKEN_KEYWORD, //! 
	TOKEN_IDENTIFIER,

	TOKEN_INT,
	TOKEN_FLOAT,
	TOKEN_CHAR,
	TOKEN_STRING,

	// Operators
	TOKEN_LSHIFT_ASSIGN,
	TOKEN_RSHIFT_ASSIGN,
	TOKEN_ELLIPSIS,
	TOKEN_ARROW,
	TOKEN_INCREMENT,
	TOKEN_DECREMENT,
	TOKEN_LEQ,
	TOKEN_GEQ,
	TOKEN_EQ,
	TOKEN_NEQ,
	TOKEN_LOGICAL_AND,
	TOKEN_LOGICAL_OR,
	TOKEN_LSHIFT,
	TOKEN_RSHIFT,
	TOKEN_ADD_ASSIGN,
	TOKEN_SUB_ASSIGN,
	TOKEN_MUL_ASSIGN,
	TOKEN_DIV_ASSIGN,
	TOKEN_AND_ASSIGN,
	TOKEN_OR_ASSIGN,
	TOKEN_INV_ASSIGN,
	TOKEN_XOR_ASSIGN,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_MUL,
	TOKEN_DIV,
	TOKEN_MOD,
	TOKEN_LESS,
	TOKEN_GREATER,
	TOKEN_NOT,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_INV,
	TOKEN_XOR,
	TOKEN_ASSIGN,
	TOKEN_QUESTION,
	TOKEN_COLON,

	// Punctuators
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_LBRACKET,
	TOKEN_RBRACKET,
	TOKEN_SEMICOLON,
	TOKEN_COMMA,
	TOKEN_DOT
} t_token_type;


/*
 * Structures
*/
typedef struct s_token {
	t_token_type type;
	const char *start;
	size_t len;
	size_t line;
	size_t col;
} t_token;


typedef struct s_token_list {
	t_token token;
	struct s_token_list *next;
} t_token_list;


/*
 * Prototypes
*/
// token_list.c
void token_list_init(t_token_list *lst);
int token_list_push(t_token_list **lst, t_token tok);
void token_list_free(t_token_list **lst);

// utils.c
void print_token_list(t_token_list *tok_lst, const char *src);


#endif
