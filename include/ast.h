#ifndef AST_H
#define AST_H


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
 * Structures
*/
typedef struct s_ast
{
	t_ast_type	type;

	union {
		struct {
			int op;    // type de token (ex: TOKEN_PLUS)
			struct s_ast *left;
			struct s_ast *right;
		} binop;

		struct {
			int op;
			struct s_ast *expr;
		} unop;

		struct {
			char *value; // ou int / double selon ton lexer
		} literal;

		struct {
			char *name;
		} identifier;
	} u;
} t_ast;


#endif
