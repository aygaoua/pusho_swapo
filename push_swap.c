/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:14:01 by azgaoua           #+#    #+#             */
/*   Updated: 2023/08/30 18:29:13 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int argc, char **argv)
{
	int	j;
	int	i;

	i = 1;
	if (argc < 2)
		exit(1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1 || argv[i][j] == ' ')
				j++;
			else if ((argv[i][j] == '-' || argv[i][j] == '+') && (j > 0 \
						&& argv[i][j - 1] != ' '))
				return (0);
			else if ((argv[i][j] == '-' || argv[i][j] == '+') \
					&& ((argv[i][j + 1] && ft_isdigit(argv[i][j + 1]) == 1)))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

long	ft_repeat_and_max(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[j])
		{
			if ((ft_atoi(av[i]) == ft_atoi(av[j]) && i != j) \
			|| ft_atoi(av[j]) == 4294967296)
				return (4294967296);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	retu;
	int		s;

	s = 1;
	i = 0;
	retu = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		retu = (retu * 10) + str[i] - 48;
		if (retu * s > 2147483647)
			return (4294967296);
		else if (retu * s < -2147483648)
			return (4294967296);
		i++;
	}
	return ((int )(retu * s));
}

char	*ft_trance(int ac, char **av)
{
	int		i;
	int		j;
	char	*res;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
			j++;
		j = 0;
		i++;
	}
	res = "\0";
	i = 1;
	while (i < ac)
	{
		res = ft_strjoin(res, av[i]);
		i++;
		if (i < ac)
			res = ft_strjoin(res, " ");
	}
	return (res);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**arrtwo;
	char			*string;
	int				k;

	k = 1;
	if (ft_error(ac, av) == 0)
		return (write(2, "Error\n", 6), 1);
	while (av[k] != NULL && k < ac)
	{
		if (ft_empty_arg(av[k]) == 0)
			return (write(2, "Error\n", 6), 1);
		k++;
	}
	k = 0;
	string = ft_trance(ac, av);
	arrtwo = ft_split(string, ' ');
	if (ft_repeat_and_max(arrtwo) == 4294967296)
		return (free(string), free(arrtwo), write(2, "Error\n", 6), 1);
	while (arrtwo[k])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(arrtwo[k++])));
	if (ft_sort_check(*a) != 1)
		ft_sort(&a, &b);
	return (0);
}
