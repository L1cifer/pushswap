/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:10:17 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:18 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*get_flags(int *t, t_stack *a)
{
	int	*flag;
	int	k;
	int	l;
	int	j;
	int	i;

	flag = (int *)ft_calloc(get_max_array(t, a->top), sizeof(int));
	if (!flag)
		exit (1);
	i = get_index_max(t, a->top, get_max_array(t, a->top));
	j = circle_in_list(a, i);
	k = i;
	l = 0;
	while (j != i)
	{
		if (a->arr[j] > a->arr[k])
		{
			flag[l] = a->arr[k];
			l++;
			k = j;
		}
		j = circle_in_list(a, j);
	}
	flag[l] = a->arr[k];
	return (flag);
}

int	get_head(t_stack *a, int i, int j)
{
	int	k;
	int	count;

	count = 1;
	k = i;
	while (j != i)
	{
		if (a->arr[j] > a->arr[k])
		{
			count++;
			k = j;
		}
		j = circle_in_list(a, j);
	}
	return (count);
}

int	*longest_list(t_stack *a, int *p)
{
	int	i;
	int	j;
	int	*t;
	int	*flag;

	t = (int *)ft_calloc(a->top + 1, sizeof(int));
	if (!t)
		exit (1);
	i = a->top;
	j = circle_in_list(a, i);
	while (i)
	{
		t[i] = get_head(a, i, j);
		i--;
		j = circle_in_list(a, i);
	}
	flag = get_flags(t, a);
	*p = get_max_array(t, a->top);
	free(t);
	return (flag);
}

void	from_a_to_b(t_stack *a, t_stack *b, int nb)
{
	while (nb != a->arr[a->top])
		rotate(a, "ra\n");
	push_top(a, b, "pb\n");
}

void	push_from_a_to_b(t_stack *a, t_stack *b)
{
	int	i;
	int	*list;
	int	index;
	int	next;

	list = longest_list(a, &index);
	i = a->top;
	while (i >= 0)
	{
		if (!is_in_arr(list, a->arr[i], index))
		{
			next = a->arr[circle_in_list(a, i)];
			from_a_to_b(a, b, a->arr[i]);
			i = get_index(a, next);
			i++;
		}
		i--;
	}
	free(list);
}
