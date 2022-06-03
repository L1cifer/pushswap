/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:08:39 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:08:49 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_bzero_gnl(char *s, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
