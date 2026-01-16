#ifndef AST_H
#define AST_H


/*
 * Includes
*/
#include "token.h"


/*
 * Enums
*/
typedef enum e_ast_type {
	// Declarations
	AST_FUNCTION_DECL,
	AST_VAR_DECL,

	AST_RETURN,
} t_ast_type;


/*
 * Forward declarations
*/
typedef struct s_ast t_ast;


typedef struct s_ast_function_decl {
	const char *function_name;
	t_ast *args;
	t_ast *body;
} t_ast_function_decl;


typedef struct s_ast_return {
	t_ast *expr;
} t_ast_return;


/*
 * Unions
*/
typedef union u_ast_node {
	t_ast_function_decl u_function_decl;
	t_ast_return u_return;
} t_ast_node;


/*
 * Structures
*/
typedef struct s_ast {
	t_ast_type type;
	t_ast_node node;
} t_ast;


/*
 * Prototypes
*/
// utils.c
void ast_print(t_ast *tree);

// ast.c






#endif
