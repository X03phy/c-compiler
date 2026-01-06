#include "token.h"
#include <stdlib.h> // malloc(), NULL, free()


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
