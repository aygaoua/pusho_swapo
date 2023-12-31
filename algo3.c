/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:21:23 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/10 17:24:39 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b(t_stack_node **a, t_stack_node **b)
{
	while (ft_lstsize(*a) != 3)
	{
		if ((*a)->next->val <= ft_get_med_valeu(*a) \
			&& (ft_lstsize(*b) > 1 && (*b)->val < (*b)->next->val))
			ft_ss(a, b);
		else if ((*a)->next->val <= ft_get_med_valeu(*a))
			ft_sa_or_b(a);
		if ((*a)->val <= ft_get_med_valeu(*a))
			ft_p_b(a, b);
		if (ft_lstsize(*a) == 3)
			break ;
		if (ft_best_med(*a) < (ft_lstsize(*a) / 2) \
			&& (ft_lstsize(*b) > 1 && ft_pos_max(*b) < (ft_lstsize(*b) / 2) \
			&& ft_pos_max(*b) != 0))
			ft_rr(a, b);
		else if (ft_best_med(*a) < (ft_lstsize(*a) / 2))
			ft_ra_or_b(a);
		if (ft_best_med(*a) >= (ft_lstsize(*a) / 2) \
			&& (ft_lstsize(*b) > 1 && ft_best_med(*b) >= (ft_lstsize(*b) / 2) \
			&& ft_pos_max(*b) != 0))
			ft_rrr(a, b);
		else if (ft_best_med(*a) >= (ft_lstsize(*a) / 2))
			ft_rra(a);
	}
}

void	ft_back_to_a(t_stack_node **a, t_stack_node **b)
{
	while (ft_lstsize(*b) != 0)
	{
		if (ft_pos_max(*b) < (ft_lstsize(*b) / 2) \
				&& ft_pos_max(*b) != 0)
			ft_rb(b);
		else if (ft_pos_max(*b) >= (ft_lstsize(*b) / 2))
			ft_rrb(b);
		if ((*a)->val > (*a)->next->val \
				&& (*b)->next->val == ft_get_max_val(*b))
			ft_ss(a, b);
		else if ((*a)->val > (*a)->next->val)
			ft_sa_or_b(a);
		if ((*b)->val == ft_get_max_val(*b))
			ft_p_a(a, b);
	}
}
