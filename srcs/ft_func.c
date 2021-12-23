/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:05:00 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 22:40:46 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	int	ft_itoa_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(unsigned int n)
{
	char			*str;
	int				i;
	int				size;
	unsigned int	tmp;

	size = ft_itoa_size(n);
	i = 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	tmp = n;
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[size - i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	str[size] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	i = -1;
	j = -1;
	str = malloc(sizeof(char) * (s1len + s2len) + 2);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = ' ';
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
