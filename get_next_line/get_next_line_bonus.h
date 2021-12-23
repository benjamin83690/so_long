/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfichot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:33:56 by bfichot           #+#    #+#             */
/*   Updated: 2021/05/11 15:59:23 by bfichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int					get_next_line(int fd, char **line);
int					has_return(char *str);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);

char				*join_str(const char *s1, const char *s2);

#endif
