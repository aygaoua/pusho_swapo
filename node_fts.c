/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:20:52 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/09 13:27:24 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstnew(long value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (0);
	new->val = value;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack_node **node, t_stack_node *new)
{
	if (!node || !new)
		return ;
	new -> next = *node;
	*node = new;
}

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last;

	if (!lst)
		return ;
	last = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		last -> next = new;
	}
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack_node *lst)
{
	t_stack_node	*j;
	int				i;

	if (!lst)
		return (0);
	j = lst;
	i = 0;
	while (j != NULL)
	{
		j = lst -> next;
		lst = lst -> next;
		i++;
	}
	return (i);
}
