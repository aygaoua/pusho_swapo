/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_fts1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:34:34 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/11 16:39:24 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free (content);
	content = NULL;
}

void	ft_lstclear(t_stack_node **lst, void (*del)(void *))
{
	t_stack_node	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del(*lst);
		*lst = tmp;
	}
	free(tmp);
}
