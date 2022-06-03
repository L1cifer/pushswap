/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:08:26 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:12:39 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_bzero_gnl(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
		s[i++] = 0;
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		str2_len;
	int		str_len;
	int		i;
	char	*str;

	str2_len = 0;
	while (s2[str2_len] && s2[str2_len] != '\n')
		str2_len++;
	if (s2[str2_len] == '\n')
		str2_len++;
	str = malloc(ft_strlen(s1) + str2_len + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	str_len = ft_strlen(str);
	i = 0;
	while (i < str2_len)
	{
		str[str_len + i] = s2[i];
		i++;
	}
	str[str_len + i] = 0;
	free(s1);
	return (str);
}
