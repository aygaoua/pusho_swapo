/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:48:35 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/11 16:26:00 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s2) + ft_strlen(s1);
	s = malloc(len + 1);
	if (!s)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	ft_memmove(s, s1, i);
	ft_memmove((s + i), s2, ft_strlen(s2));
	s[len] = '\0';
	if (s1)
		free(s1);
	return (s);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (d == 0 && s == 0)
		return (0);
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		d = ft_memcpy(d, s, len);
	return (d);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (0);
	d = (char *)dst;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
