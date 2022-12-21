#include "push_swap.h"

static void	ft_putbest_free(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb);

char	*ft_putbest(t_list **a, t_list **b, char *result)
{
	t_list	**ra;
	t_list	**rra;
	t_list	**rb;
	t_list	**rrb;
	int		*moves;

	ra = ft_get_nb_ra(ft_lstdup(b), a);
	rra = ft_get_nb_rra(ft_lstdup(b), a);
	rb = ft_get_nb_rb(ft_lstdup(b));
	rrb = ft_get_nb_rrb(ft_lstdup(b));
	if (ra == NULL || rra == NULL || rb == NULL || rrb == NULL)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		return (NULL);
	}
	ft_getallbestmoves(ra, rra, rb, rrb);
	moves = ft_getthebestmoves(ra, rra, rb, rrb);
	if (!moves)
	{
		ft_putbest_free(ra, rra, rb, rrb);
		return (NULL);
	}
	result = ft_makethebestmoves(a, b, result, moves);
	ft_putbest_free(ra, rra, rb, rrb);
	free(moves);
	return (result);
}

static void	ft_putbest_free(t_list **ra, t_list **rra,
				t_list **rb, t_list **rrb)
{
	ft_lstclear(ra, (void *)free);
	ft_lstclear(rra, (void *)free);
	ft_lstclear(rb, (void *)free);
	ft_lstclear(rrb, (void *)free);
	free(ra);
	free(rra);
	free(rb);
	free(rrb);
}
