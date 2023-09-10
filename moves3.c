/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:00:18 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/07 02:05:07 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb_pls(t_stack_node **b)
{
	if (b == NULL || (*b)->next == NULL)
		return ;
	ft_swap(&(*b)->next->val, &(*b)->val);
}

void	ft_rb_pls(t_stack_node **b)
{
	t_stack_node	*first_list;
	t_stack_node	*rotate_list;
	t_stack_node	*last_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate_list = *b;
	first_list = (*b)->next;
	last_list = *b;
	while (last_list->next != NULL)
		last_list = last_list->next;
	rotate_list->next = NULL;
	last_list->next = rotate_list;
	*b = first_list;
}

void	ft_rra_pls(t_stack_node **a, int i)
{
	t_stack_node	*first_list;
	t_stack_node	*rotate_list;
	t_stack_node	*penultimate_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	first_list = *a;
	penultimate_list = *a;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*a = rotate_list;
	i = 1;
	i++;
}

void	ft_rrb_pls(t_stack_node **b, int i)
{
	t_stack_node	*first_list;
	t_stack_node	*rotate_list;
	t_stack_node	*penultimate_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	first_list = *b;
	penultimate_list = *b;
	while (penultimate_list->next->next != NULL)
		penultimate_list = penultimate_list->next;
	rotate_list = penultimate_list->next;
	penultimate_list->next = NULL;
	rotate_list->next = first_list;
	*b = rotate_list;
	i = 1;
	i++;
}
