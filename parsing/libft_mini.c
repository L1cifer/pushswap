/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:09:34 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:09:36 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*c;

	i = 0;
	l = ft_strlen(s1);
	c = (char *)malloc(sizeof(char) * l + 1);
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!src && !dst)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d > s)
		while (len--)
			*(d + len) = *(s + len);
	else
	{
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;
	size_t	lt;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	lt = l1 + l2;
	str = malloc(lt + 1);
	if (!str)
		return (0);
	ft_memmove(str, s1, l1);
	ft_memmove((str + l1), s2, l2);
	*(str + l1 + l2) = 0;
	return (str);
}
