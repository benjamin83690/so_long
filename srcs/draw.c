/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:57:38 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 22:58:10 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw(t_data *data)
{
	data->i = 0;
	data->y = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		data->x = 0;
		while (data->map[data->i][data->j])
		{
			draw_map(data->map[data->i][data->j], data);
			data->x += 32;
			data->j++;
		}
		data->i++;
		data->y += 32;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	draw_count(t_data *data)
{
	char	*str;
	char	*tmp;
	char	*final;

	tmp = "move=";
	str = ft_itoa(data->move);
	final = ft_strjoin(tmp, str);
	mlx_string_put(data->mlx, data->mlx_win, 10, 0, 0, final);
	free(str);
	free(final);
}

void	draw_player(t_data *data)
{
	draw_square(data, 0x00FFFFFF, data->playerx, data->playery);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	draw_square(t_data *data, int color, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->posx)
	{
		while (j < data->posy)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}
