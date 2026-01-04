#include "token.h"


void token_list_init(t_token_list *lst)
{
	lst->next = NULL;
}


int token_list_push(t_token_list **lst, t_token tok)
{
	t_token_list *new;
	t_token_list *cur;

	if (!lst)
		return (0);

	new = malloc(sizeof(t_token_list));
	if (!new)
		return (0);

	new->token = tok;
	new->next = NULL;

	if (*lst == NULL) {
		*lst = new;
		return (1);
	}

	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;

	return (1);
}


void token_list_free(t_token_list **lst)
{
	t_token_list *cur;

	if (!lst)
		return;

	while (*lst) {
		cur = *lst;
		*lst = (*lst)->next;
		free(cur);
	}
	*lst = NULL;
}


//void print_token_list(t_token_list *lst)
//{
//	static const char *names[] = {
//		[TOKEN_EOF]        = "EOF",
//		[TOKEN_ERROR]      = "ERROR",
//		[TOKEN_KEYWORD]    = "KEYWORD",
//		[TOKEN_IDENTIFIER] = "IDENTIFIER",
//		[TOKEN_CONSTANT]   = "CONSTANT",
//		[TOKEN_STRING]     = "STRING",
//		[TOKEN_OPERATOR]   = "OPERATOR",
//		[TOKEN_PUNCTUATOR] = "PUNCTUATOR"
//	};

//	int i = 0;
//	while (lst) {
//		printf("%s: %s\n", names[lst->token->type], substr());
//		i++;
//		lst = lst->next;
//	}
//}
