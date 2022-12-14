#include "push_swap.h"

void 	*ft_contdup(void *content);

t_list **ft_lstdup(t_list **lst)
{
	t_list	**dup;
	t_list	*temp;
	void	*content;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	dup = (t_list **)malloc(sizeof(t_list *));
	if (dup == NULL)
		return (NULL);
	*dup = NULL;
	temp = *lst;
	while (temp != NULL)
	{
		content = ft_contdup(temp->content);
		ft_lstadd_back(dup, ft_lstnew(content));
		if (content == NULL || content != ft_lstlast(*dup)->content) 
		{
			ft_lstclear(dup, (void *)free);
			free(content);
			free(dup);
			return (NULL);
		}
		temp = temp->next;
	}
	return (dup);
}