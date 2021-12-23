/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:00:14 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 20:02:37 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data *data, char *map)
{
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->posx = 32;
	data->posy = 32;
	data->playerx = 0;
	data->playery = 0;
	data->map = read_map(map);
	data->i = 0;
	data->j = 0;
	data->x = 0;
	data->y = 0;
	data->collect = 0;
	data->move = 0;
}

void	init_letter(t_letter *letter)
{
	letter->c = 0;
	letter->p = 0;
	letter->e = 0;
}
