/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:41:44 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/21 12:59:36 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_solve_exit(t_list **a, t_list **b, char *result);
static char	*ft_pballbutx(t_list **src, t_list **dst, int x, char *result);

char	*ft_solve(t_list **a, char *result)
{
	t_list	**b;

	b = (t_list **)malloc(sizeof(t_list *));
	if (b == NULL)
		ft_solve_exit(a, b, result);
	*b = NULL;
	
	if (ft_issorted(a))//first check
	{
		free(b);
		return (result);
	}
	if (ft_iscis(a))//second check
	{
		result = ft_cistosorted(a, result);
		if (!result)
			ft_solve_exit(a, b, result);
		ft_lstclear(a, (void *)free);
		ft_lstclear(b, (void *)free);
		free(b);
		return (result);
	}

	result = ft_pballbutx(a, b, 3, result);//preparation for entering loop
	if (!result)
		ft_solve_exit(a, b, result);
	if (!ft_iscis(a))
		result = ft_saveswap(a, result, "sa\n\0");
	if (!result)
		ft_solve_exit(a, b, result);
	while (ft_lstsize(*b) != 0)//loop
	{
		result = ft_putbest(a, b, result);
		if (!result)
			ft_solve_exit(a, b, result);
	}
	
	if (!ft_issorted(a))//last check
		result = ft_cistosorted(a, result);
	if (!result)
		ft_solve_exit(a, b, result);
		
	ft_lstclear(a, (void *)free);//cleaning
	ft_lstclear(b, (void *)free);
	free(b);
	return (result);
}

/*
static char *ft_solve_a(t_list **a, t_list **b, char *result)
{
	if (ft_issorted(a))//first check
	{
		free(b);
		return (result);
	}
	if (ft_iscis(a))//second check
	{
		result = ft_cistosorted(a, result);
		if (!result)
			ft_solve_exit(a, b, result);
		ft_lstclear(a, (void *)free);
		ft_lstclear(b, (void *)free);
		free(b);
		return (result);
	}
}*/

/*
char	*ft_solve(t_list **a)
{
	char	*result;
	t_list	**b;

	result = malloc(sizeof(char));//initiation
	b = (t_list **)malloc(sizeof(t_list *));
	if (result == NULL || b == NULL)
		ft_solve_exit(a, b, result);
	result[0] = '\0';
	if (b != NULL)
		*b = NULL;
		
	if (ft_issorted(a))//first check
	{
		free(b);
		return (result);
	}
	if (ft_iscis(a))//second check
	{
		result = ft_cistosorted(a, result);
		if (!result)
			ft_solve_exit(a, b, result);
		ft_lstclear(a, (void *)free);
		ft_lstclear(b, (void *)free);
		free(b);
		return (result);
	}
	
	result = ft_pballbutx(a, b, 3, result);//preparation for entering loop
	if (!result)
		ft_solve_exit(a, b, result);
	if (!ft_iscis(a))
		result = ft_saveswap(a, result, "sa\n\0");
	if (!result)
		ft_solve_exit(a, b, result);
	while (ft_lstsize(*b) != 0)//loop
	{
		result = ft_putbest(a, b, result);
		if (!result)
			ft_solve_exit(a, b, result);
	}
	
	if (!ft_issorted(a))//last check
		result = ft_cistosorted(a, result);
	if (!result)
		ft_solve_exit(a, b, result);
		
	ft_lstclear(a, (void *)free);//cleaning
	ft_lstclear(b, (void *)free);
	free(b);
	return (result);
}
*/

static void	ft_solve_exit(t_list **a, t_list **b, char *result)
{
	if (result != NULL)
		free(result);
	ft_lstclear(a, (void *)free);
	ft_lstclear(b, (void *)free);
	free(a);
	free(b);
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static char	*ft_pballbutx(t_list **src, t_list **dst, int x, char *result)
{
	int		i;
	char	*new_result;

	i = ft_lstsize(*src);
	if (x < 0)
		x = 0;
	new_result = result;
	while (i > x)
	{	
		new_result = ft_savepush(src, dst, new_result, "pb\n\0");
		if (!new_result)
			return (NULL);
		i--;
	}
	return (new_result);
}
