/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:32:59 by bfichot           #+#    #+#             */
/*   Updated: 2021/05/17 15:35:48 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_content(char *content)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!content)
		return (0);
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (0);
	}
	rest = malloc(sizeof(char) * (ft_strlen(content) - i) + 1);
	if (rest == NULL)
		return (0);
	i++;
	while (content[i])
		rest[j++] = content[i++];
	rest[j] = '\0';
	free(content);
	return (rest);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	ft_read(int fd, char **content, int ret, char *buff)
{
	while (!has_return(content[fd]) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			break ;
		}
		buff[ret] = '\0';
		content[fd] = join_str(content[fd], buff);
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*content[255];
	int				ret;

	ret = 1;
	if (fd < 0 || !line || fd > 255 || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	ret = ft_read(fd, content, ret, buff);
	if (ret == -1)
		return (-1);
	free(buff);
	*line = get_line(content[fd]);
	content[fd] = get_content(content[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
