/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:28:50 by azgaoua           #+#    #+#             */
/*   Updated: 2023/08/30 18:29:01 by azgaoua          ###   ########.fr       */
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
