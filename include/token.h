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
	TOKEN_EOF,
	TOKEN_ERROR,
	TOKEN_KEYWORD,
	TOKEN_IDENTIFIER,
	TOKEN_CONSTANT, //! A affiner : int, float, char
	TOKEN_STRING,
	TOKEN_OPERATOR,
	TOKEN_PUNCTUATOR, // punctuators: ( ) [ ] { } * , : = ; ... #
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
