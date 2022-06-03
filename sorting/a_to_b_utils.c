/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:10:07 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:08 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index_max(int *arr, int size, int n)
{
	int	i;

	i = size;
	while (i >= 0)
	{
		if (arr[i] == n)
			return (i);
		i--;
	}
	return (i);
}

int	get_index(t_stack *stack, int m)
{
	int	i;

	i = 0;
	while (stack->arr[i] != m)
		i++;
	return (i);
}

int	is_in_arr(int *arr, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	get_max_array(int *arr, int size)
{
	int	i;
	int	max;

	i = 0;
	max = arr[0];
	while (i <= size)
	{
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}

int	circle_in_list(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (n > 0)
			n--;
		else
			n = stack->top;
		i++;
	}
	return (n);
}
