/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:02:41 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 20:12:33 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_func(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 1)
	{
		if (data->map[(data->playery / 32) + 1][(data->playerx / 32)] != '1')
		{
			data->playery += 32;
			data->move++;
		}
	}
	if (keycode == 53)
		kill_the_window(data);
	key_func_bis(keycode, data);
	draw(data);
	draw_player(data);
	draw_count(data);
	return (keycode);
}

void	key_func_bis(int keycode, t_data *data)
{
	if (keycode == 2)
	{
		if (data->map[(data->playery / 32)][(data->playerx / 32) + 1] != '1')
		{
			data->move++;
			data->playerx += 32;
		}
	}
	if (keycode == 0)
	{
		if (data->map[(data->playery / 32)][(data->playerx / 32) - 1] != '1')
		{
			data->move++;
			data->playerx -= 32;
		}
	}
	if (keycode == 13)
	{
		if (data->map[(data->playery / 32) - 1][(data->playerx / 32)] != '1')
		{
			data->move++;
			data->playery -= 32;
		}
	}
}

void	draw_map(char c, t_data *data)
{
	if (c == '1')
		draw_square(data, 0x00999999, data->x, data->y);
	if (c == 'P')
	{
		data->playerx = data->i * 32;
		data->playery = data->j * 32;
		data->map[data->i][data->j] = '0';
	}
	if (c == 'C')
	{
		if (data->playerx == data->x && data->playery == data->y)
		{
			data->map[data->i][data->j] = '0';
			data->collect--;
		}
		else
			draw_square(data, 0x00FF0000, data->x, data->y);
	}
	draw_map_bis(c, data);
}

void	draw_map_bis(char c, t_data *data)
{
	if (c == '0')
		draw_square(data, 0x00009900, data->x, data->y);
	if (c == 'E')
	{
		if (data->collect == 0 && data->playerx
			== data->x && data->playery == data->y)
			exit(1);
		else
			draw_square(data, 0x00330033, data->x, data->y);
	}
}
