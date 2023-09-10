/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 01:53:19 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/07 02:08:02 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack_node **a, t_stack_node **b)
{
	ft_sa_or_b_pls(a);
	ft_sb_pls(b);
	write(1, "ss\n", 3);
}

void	ft_rr(t_stack_node **a, t_stack_node **b)
{
	ft_ra_or_b_pls(a);
	ft_rb_pls(b);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack_node **a, t_stack_node **b)
{
	ft_rra_pls(a, 0);
	ft_rrb_pls(b, 0);
	write(1, "rrr\n", 4);
}

void	ft_sa_or_b_pls(t_stack_node **a)
{
	if (a == NULL || (*a)->next == NULL)
		return ;
	ft_swap(&(*a)->val, &(*a)->next->val);
}

void	ft_ra_or_b_pls(t_stack_node **a)
{
	t_stack_node	*first_list;
	t_stack_node	*rotate_list;
	t_stack_node	*last_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	first_list = (*a)->next;
	last_list = *a;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*a = first_list;
}
