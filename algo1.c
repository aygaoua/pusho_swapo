/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:05:14 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/11 17:44:10 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_fv(t_stack_node **a, t_stack_node **b)
{
	int	i;

	while (ft_lstsize(*a) != 3)
	{
		i = ft_pos_min(*a);
		if (i > (ft_lstsize(*a) / 2) && i != 0)
			ft_rra(a);
		else if (i != 0 && i <= (ft_lstsize(*a) / 2))
			ft_ra_or_b(a);
		if ((*a)->val == ft_get_smallest_valeu(*a))
			ft_p_b(a, b);
	}
	if (ft_sort_check(**a) == 0)
		ft_sort_tr(a);
	if (ft_sort_check(**b) != 0)
		ft_sb(b);
	while (ft_lstsize(*b) != 0)
		ft_p_a(a, b);
	exit (0);
}

int	ft_pos_min(t_stack_node *a)
{
	int		smallest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	smallest = a->val;
	while (a != NULL)
	{
		if (a->val < smallest)
		{
			smallest = a->val;
			j = i;
		}
		i++;
		a = a->next;
	}
	return (j);
}

int	ft_pos_max(t_stack_node *a)
{
	int		max;
	int		i;
	int		j;

	i = 0;
	j = 0;
	max = a->val;
	while (a != NULL)
	{
		if (a->val >= max)
		{
			max = a->val;
			j = i;
		}
		i++;
		a = a->next;
	}
	return (j);
}

int	ft_sort_stack(t_stack_node **a, t_stack_node **b)
{
	ft_push_to_b(a, b);
	ft_sort_tr(a);
	ft_back_to_a(a, b);
	ft_lstclear(b, del);
	ft_lstclear(a, del);
	exit (0);
}
