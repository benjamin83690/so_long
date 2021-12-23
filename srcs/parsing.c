/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:09:55 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 23:38:47 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**read_map(char *map)
{
	int		fd;
	char	**mappy;
	char	*line;
	int		i;

	line = NULL;
	fd = open(map, O_RDONLY);
	i = search_len(fd, line);
	fd = open(map, O_RDONLY);
	mappy = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		mappy[i] = ft_strdup(line);
		free(line);
		i++;
	}
	mappy[i] = NULL;
	free(line);
	close(fd);
	return (mappy);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int	check_letter(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C' )
		return (1);
	else
	{
		printf("caractere different de ceux demande");
		return (0);
	}
}
