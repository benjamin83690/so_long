/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:17:51 by bfichot           #+#    #+#             */
/*   Updated: 2021/12/21 23:34:57 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER_SIZE 1;

typedef struct s_letter
{
	int	c;
	int	p;
	int	e;
}		t_letter;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		posx;
	int		posy;
	int		playerx;
	int		playery;
	char	**map;
	char	indice;
	int		i;
	int		j;
	int		x;
	int		y;
	int		collect;
	int		move;
}			t_data;

int		check_letter(char c);
int		search_len(int fd, char *line);
int		check_map(char **tab, t_letter *letter);
int		is_only_one(char *str);
int		len_tab(char **tab);
int		check_arg(char **tab, t_letter *letter);
int		message_error(t_letter *letter);
int		message_error_bis(char **tab, int len, int i);
int		key_func(int keycode, void *param);
int		kill_the_window(t_data *data);
int		check_format(char *av);
int		search_point(char *av);

void	init_letter(t_letter *letter);
void	draw_square(t_data *data, int color, int x, int y);
void	free_tab(char **tab);
void	print_tab(char **tab);
void	draw(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_data(t_data *data, char *map);
void	draw_map(char c, t_data *data);
void	draw_player(t_data *data);
void	key_func_bis(int keycode, t_data *data);
void	draw_map_bis(char c, t_data *data);
void	draw_count(t_data *data);
void	start_window(t_data *data, char **mappy);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(unsigned int n);
char	**read_map(char *map);
char	*ft_strdup(char *str);
#endif
