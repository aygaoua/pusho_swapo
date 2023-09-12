/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:24:46 by aygaoua           #+#    #+#             */
/*   Updated: 2023/09/12 13:59:23 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_med_valeu(t_stack_node *a)
{
	int		med;
	int		*tab;

	med = 0;
	tab = ft_lst_to_tab(a);
	ft_sort_int_tab(tab, ft_lstsize(a));
	if (ft_lstsize(a) <= 100)
		med = tab[ft_lstsize(a) / 5];
	else if (ft_lstsize(a) <= 500)
		med = tab[ft_lstsize(a) / 10];
	else
		med = tab[ft_lstsize(a) / 15];
	free(tab);
	return (med);
}

int	*ft_lst_to_tab(t_stack_node *a)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * ft_lstsize(a));
	while (a != NULL)
	{
		tab[i] = a->val;
		a = a->next;
		i++;
	}
	return (tab);
}

int	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] < tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_sort_tr_b(t_stack_node **b)
{
	int	m;

	m = ft_get_smallest_valeu(*b);
	if ((*b)->val == m)
		ft_rb(b);
	else if ((*b)->next->val == m)
		ft_rrb(b);
	else if (ft_sort_check(**b) == 0)
		ft_sb(b);
	return ;
}

int	ft_best_med(t_stack_node *a)
{
	int	*tab;
	int	i;
	int	med;
	int	best;

	i = 0;
	tab = ft_lst_to_tab(a);
	ft_sort_int_tab(tab, ft_lstsize(a));
	if (ft_lstsize(a) <= 100)
		med = tab[ft_lstsize(a) / 5];
	else if (ft_lstsize(a) <= 500)
		med = tab[ft_lstsize(a) / 10];
	else
		med = tab[ft_lstsize(a) / 15];
	best = 0;
	while (i < ft_lstsize(a))
	{
		if (tab[i] < med)
			best = i;
		i++;
	}
	free(tab);
	return (best);
}
