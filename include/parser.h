#ifndef PARSER_H
#define PARSER_H


/*
 * Includes
*/
#include <stddef.h> // size_t
#include "token.h"
#include "ast.h"


/*
 * Structures
*/
typedef struct s_parser
{
	t_token *tokens;
	size_t	pos;
} t_parser;


/*
 * Prototypes
*/
// parser.c
t_ast *parser(t_token_list *token_list);


#endif
