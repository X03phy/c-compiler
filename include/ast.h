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
	AST_PROGRAM,

	AST_FUNCTION,
	AST_VAR_DECL,

	AST_RETURN,
} t_ast_type;



/*
 * Forward declaration
*/
t_ast;



typedef struct s_ast_program {
	t_ast **decls;
	size_t count;
} t_ast_program;


typedef struct s_ast_binary {
	t_token_type op;
	t_ast *left;
	t_ast *right;
} t_ast_binary;


typedef struct s_ast_return {
	t_ast *expr;
} t_ast_return;


/*
 * Unions
*/
typedef union u_ast_node {
	struct function_definition {
		char *name;
		void *args;
		t_ast *body;          // compound stmt
	} t_ast_function;
} t_ast_node;


/*
 * Structures
*/
typedef struct s_ast
{
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
