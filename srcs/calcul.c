/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:04:48 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 19:57:15 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	is_only_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	search_point(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
			return (i);
		i++;
	}
	return (0);
}

int	search_len(int fd, char *line)
{
	int	len;

	len = 0;
	while (get_next_line(fd, &line))
	{
		len++;
		free(line);
	}
	free(line);
	close(fd);
	return (len);
}
