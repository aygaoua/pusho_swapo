/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:19:45 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/07 01:56:24 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(long *a, long *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void	ft_sa_or_b(t_stack_node **a)
{
	if (a == NULL || (*a)->next == NULL)
		return ;
	ft_swap(&(*a)->val, &(*a)->next->val);
	write(1, "sa\n", 3);
}

void		ft_sb(t_stack_node **b)
{
	if (b == NULL || (*b)->next == NULL)
		return ;
	ft_swap(&(*b)->next->val, &(*b)->val);
	write(1, "sb\n", 3);
}

void	ft_ra_or_b(t_stack_node **a)
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
	write(1, "ra\n", 3);
}

void	ft_rra(t_stack_node **a, int i)
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
	write(1, "rra\n", 4);
}
