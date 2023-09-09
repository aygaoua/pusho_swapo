/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:05:14 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/09 17:41:23 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_fv(t_stack_node **a, t_stack_node **b)
{
	int i;
	int pass;
	
	pass = 0;
	while (ft_lstsize(*a) != 3)
	{
		i = ft_pos_min(*a);
		if ((*a)->val == ft_get_smallest_valeu(*a))
		{
			pass = 1;
			ft_p_b(a, b);
		}
		if(i > (ft_lstsize(*a) / 2) && pass != 1)
			ft_rra(a ,0);
		else if (pass != 1 && i <= (ft_lstsize(*a) / 2))
			ft_ra_or_b(a);
		pass = 0;
	}
	if (ft_sort_check(**a) == 0)
		ft_sort_tr(a);
	if (ft_sort_rev_check(**b) != 1)
		ft_sb(b);
	while (ft_lstsize(*b) != 0)
		ft_p_a(a, b);
	exit (1);
}

int	ft_sort_rev_check(t_stack_node b)
{
	while (b.next != NULL)
	{
		if (b.next && b.val > b.next->val)
			b = *b.next;
		else
			return (0);
	}
	return (1);
}

int		ft_pos_min(t_stack_node *a)
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

int		ft_pos_max(t_stack_node *a)
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

int		ft_sort_stack(t_stack_node **a, t_stack_node **b)
{
	int pass;

	pass = 0;
	while (ft_lstsize(*a) != 3)
	{
		if ((*a)->next->val <= ft_get_med_valeu(*a) && (ft_lstsize(*b) > 1 && (*b)->val < (*b)->next->val))
			ft_ss(a, b);
		else
		{	
			if((*a)->next->val <= ft_get_med_valeu(*a))
				ft_sa_or_b(a);
			if (ft_lstsize(*b) > 1 && (*b)->val < (*b)->next->val)
				ft_sb(b);
		}
		if ((*a)->val <= ft_get_med_valeu(*a))
			ft_p_b(a, b);
		if (ft_lstsize(*a) == 3)
			break ;
		if (ft_best_med(*a) < (ft_lstsize(*a) / 2))
			ft_ra_or_b(a);
		else if (ft_best_med(*a) >= (ft_lstsize(*a) / 2))
			ft_rra(a, 0);
	}
	ft_sort_tr(a);
	while (ft_lstsize(*b) != 0)
	{
		if (ft_lstsize(*b) != 1)
		{
			while (ft_sort_check(**a) == 0)
			{
				if ((*a)->val > (*a)->next->val && (*b)->next->val == ft_get_max_val(*b))
					ft_ss(a, b);
				if ((*a)->val > (*a)->next->val)
					ft_sa_or_b(a);
				if ((*b)->next->val == ft_get_max_val(*b))
					ft_sb(b);
			}
			if ((*b)->val == ft_get_max_val(*b))
			{
				ft_p_a(a, b);
				if (ft_lstsize(*b) == 1)
					break ;
			}
			if (ft_pos_max(*b) >= (ft_lstsize(*b) / 2) && ft_pos_max(*b) != 0)
				ft_rrb(b, 0);
			if (ft_pos_max(*b) < (ft_lstsize(*b) / 2) && ft_pos_max(*b) != 0)
				ft_rb(b);
		}
	}
	if (ft_lstsize(*b) == 1)
			ft_p_a(a, b);
	exit (0);
}
