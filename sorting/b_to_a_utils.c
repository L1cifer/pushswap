/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:10:12 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:13 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_index(int *arr, int size)
{
	int	index;
	int	min;
	int	i;

	index = 0;
	min = arr[index];
	i = 0;
	while (i < size)
	{
		if (arr[i] <= min)
		{
			index = i;
			min = arr[index];
		}
		i++;
	}
	return (index);
}

int	is_get_min(t_stack *a)
{
	int	min;
	int	i;

	min = a->arr[0];
	i = 0;
	while (i <= a->top)
	{
		if (a->arr[i] < min)
			min = a->arr[i];
		i++;
	}
	return (min);
}

int	get_next_nb(t_stack *a, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->top)
	{
		j = circle_in_list(a, i);
		if (a->arr[i] < nb && a->arr[j] > nb)
			return (a->arr[j]);
		i++;
	}
	return (is_get_min(a));
}
