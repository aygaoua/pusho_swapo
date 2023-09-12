/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:28:50 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/12 15:30:59 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}

int	ft_empty_arg(char *c)
{
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (c[j] != '\0')
	{
		if (ft_isdigit(c[j]))
			k++;
		j++;
	}
	return (k);
}

void	ft_free_stacks(t_stack_node **a, t_stack_node **b)
{
	if (a)
		ft_lstclear(a, del);
	if (b)
		ft_lstclear(b, del);
}

int	ft_errors(int ac, char **av)
{
	int	k;

	k = 1;
	while (av[k] != NULL && k < ac)
	{
		if (ft_empty_arg(av[k]) == 0)
			return (1);
		k++;
	}
	return (0);
}
