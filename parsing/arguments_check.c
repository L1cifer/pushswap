/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:09:15 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:09:19 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	array_check(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-' || arr[i][j] == '+')
				j++;
			if (ft_isdigit(arr[i][j]) || duplicate(arr))
				return (1);
			if (arr[i][j + 1] == '+' || arr[i][j + 1] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	spaces_check(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == spaces_count(av[i]))
			return (1);
		i++;
	}
	return (0);
}

char	**array_split(int ac, char **av)
{
	char	**arr;
	char	*tmp;
	char	*arg;
	int		i;

	tmp = (char *)malloc(1 * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (spaces_check(av))
		print_error();
	i = 1;
	while (i < ac)
	{
		arg = ft_strjoin(tmp, av[i++]);
		free(tmp);
		tmp = ft_strjoin(arg, " ");
		free(arg);
	}
	arr = ft_split(tmp, ' ');
	free (tmp);
	return (arr);
}

int	check_limits(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (ft_atoi(arr[i]) < MIN || ft_atoi(arr[i]) > MAX)
			return (1);
		i++;
	}
	return (0);
}

char	**array_filling(int ac, char **av, int *i)
{
	char	**arr;

	if (ac == 1)
		exit(1);
	arr = array_split(ac, av);
	if (array_check(arr))
		print_error();
	if (check_limits(av))
		print_error();
	while (arr[*i])
		(*i)++;
	return (arr);
}
