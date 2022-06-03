/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mini3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:09:49 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:09:50 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)b;
	while (i < len)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	m;
	char	*p;

	m = count * size;
	p = malloc(m);
	if (p == 0)
		return (NULL);
	ft_bzero(p, m);
	return (p);
}
