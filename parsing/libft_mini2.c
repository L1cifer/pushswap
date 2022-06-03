/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mini2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:09:44 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:09:45 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

int	duplicate(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (str);
}

size_t	spaces_count(char *av)
{
	int		i;
	size_t	num;

	i = 0;
	num = 0;
	while (av[i])
	{
		if (av[i] == 32 || (av[i] >= 9 && av[i] <= 13))
			num++;
		i++;
	}
	return (num);
}
