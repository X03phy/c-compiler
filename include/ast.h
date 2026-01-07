#ifndef AST_H
#define AST_H


/*
 * Includes
*/
#include "token.h"


/*
 * Enums
*/
typedef enum e_ast_type
{
	AST_BINOP,     // a + b, a * b, a == b
	AST_UNOP,      // -a, !a
	AST_LITERAL,   // nombre, string
	AST_IDENTIFIER // variable
} t_ast_type;


/*
 * Unions
*/
typedef union u_ast {
	struct {
		t_token_type op;
		struct s_ast *left;
		struct s_ast *right;
	} bin;

	struct {
		t_token_type op;
		struct s_ast *expression;
	} un;

	struct {
		const char *value; // ou int / double selon ton lexer
	} literal;

	struct {
		const char *name;
	} identifier;
} t_ast_u;


/*
 * Structures
*/
typedef struct s_ast
{
	t_ast_type type;
	t_ast_u u;
} t_ast;


/*
 * Prototypes
*/
// utils.c
void ast_print(t_ast *tree);

// ast.c






#endif
