/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:11:43 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 23:39:03 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_format(char *av)
{
	int	i;
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(printf("fichier n'existe pas! \n"));
	i = search_point(av);
	if (av[i] == '.' && av[i + 1] == 'b' && av[i + 2]
		== 'e' && av[i + 3] == 'r' && av[i + 4] == '\0')
		return (1);
	else
		exit(printf("format de map non conforme!"));
	return (0);
}

int	check_map(char **tab, t_letter *letter)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(tab[i]);
	if (!is_only_one(tab[0]) || !is_only_one(tab[len_tab(tab) - 1]))
	{
		printf("premiere ligne ou derniere ligne ne contenant pas que des 1\n");
		return (0);
	}
	while (tab[i])
	{
		if (!message_error_bis(tab, len, i))
			return (0);
		i++;
	}
	if (!check_arg(tab, letter))
		return (0);
	return (1);
}

int	check_arg(char **tab, t_letter *letter)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (tab[i])
	{
		while (tab[i][y])
		{
			if (!(check_letter(tab[i][y])))
				return (0);
			if (tab[i][y] == 'E')
				letter->e += 1;
			if (tab[i][y] == 'P')
				letter->p += 1;
			if (tab[i][y] == 'C')
				letter->c += 1;
			y++;
		}
		y = 0;
		i++;
	}
	if (!message_error(letter))
		return (0);
	return (1);
}

int	message_error(t_letter *letter)
{
	if (letter->p > 1 || letter->p == 0)
	{
		printf("plus d'un player, ou pas de player\n");
		return (0);
	}
	if (letter->c < 1 || letter->e < 1)
	{
		printf("il manque une sortie ou un collectable\n");
		return (0);
	}
	return (1);
}

int	message_error_bis(char **tab, int len, int i)
{
	if (tab[i][0] != '1' || tab[i][ft_strlen(tab[i]) - 1] != '1')
	{
		printf("pas de contour de map avec des 1\n");
		return (0);
	}
	if ((int)ft_strlen(tab[i]) != len)
	{
		printf("ce nest pas un rectangle!!");
		return (0);
	}
	return (1);
}
