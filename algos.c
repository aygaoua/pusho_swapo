/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:30:56 by aygaoua           #+#    #+#             */
/*   Updated: 2023/09/07 00:46:35 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(t_stack_node a)
{
	while (a.next != NULL)
	{
		if (a.next && a.val < a.next->val)
			a = *a.next;
		else
			return (0);
	}
	return (1);
}

int	ft_get_smallest_valeu(t_stack_node *a)
{
	int		smallest;

	smallest = a->val;
	while (a != NULL)
	{
		if (a->val < smallest)
			smallest = a->val;
		a = a->next;
	}
	// printf("smallest = %d\n", smallest);
	return (smallest);
}

int	ft_get_max_val(t_stack_node *a)
{
	int		max;

	if (ft_lstsize(a) == 1)
		return (a->val);
	max = a->val;
	while (a != NULL)
	{
		if (a->val > max)
			max = a->val;
		a = a->next;
	}
	return (max);
}

int	ft_sort_tr(t_stack_node **a)
{
	int m;

	m = ft_get_max_val(*a);
	if ((*a)->val == m)
		ft_ra_or_b(a);
	else if ((*a)->next->val == m)
		ft_rra(a, 0);
	if(ft_sort_check(**a) == 0)
		ft_sa_or_b(a);
	return (1);
}

int	ft_sort(t_stack_node **a, t_stack_node **b)
{
	int i;
	if (ft_lstsize(*a) == 3)
		ft_sort_tr(a);
	else if (ft_lstsize(*a) == 5 || ft_lstsize(*a) == 4)
		ft_sort_fv(a, b);
	else if (ft_lstsize(*a) < 3)
	{
		i = ft_get_smallest_valeu(*a);
		while (ft_sort_check(**a) == 0)
		{
			if ((*a)->val > (*a)->next->val && (*a)->next->val != i)
				ft_sa_or_b(a);
			else if (ft_pos_min(*a) > (ft_lstsize(*a) / 2))
				ft_ra_or_b(a);
			else
				ft_rra(a, 0);
		}
	}
	else
		ft_sort_stack(a, b);
	return (1);
}
