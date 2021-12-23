/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:11:46 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/22 15:21:54 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	start_window(t_data *data, char **mappy)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 32 * ft_strlen(mappy[0]),
			32 * len_tab(mappy), "test");
	data->img = mlx_new_image(data->mlx, 32 * ft_strlen(mappy[0]),
			32 * len_tab(mappy));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	kill_the_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (1);
	return (0);
}

int	main(int ac, char **av)
{
	char		**mappy;
	t_letter	letter;
	t_data		data;

	if (ac != 2)
		return (printf("erreur arguments : <executable> <path_map>"));
	init_letter(&letter);
	check_format(av[1]);
	mappy = read_map(av[1]);
	init_data(&data, av[1]);
	if (check_map(mappy, &letter) == 0)
		return (0);
	start_window(&data, mappy);
	data.collect = letter.c;
	draw(&data);
	draw_player(&data);
	mlx_key_hook(data.mlx_win, key_func, &data);
	mlx_hook(data.mlx_win, 17, 0, kill_the_window, &data);
	mlx_loop(data.mlx);
	free_tab(mappy);
	free_tab(data.map);
}
