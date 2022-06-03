/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:09:58 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:00 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_num_sort(t_stack *a, t_stack *b, int n)
{
	if (n == 1)
		exit(0);
	else if (n == 2)
		sort_2(a);
	else if (n == 3)
		sort_3(a);
	else if (n == 5)
		sort_5(a, b);
	else
		return ;
}

void	sort_2(t_stack *a)
{
	if (a->arr[0] < a->arr[1])
		swap(a, "sa\n");
}

void	sort_3(t_stack *a)
{
	int	*t;

	t = a->arr;
	if (t[0] > t[2] && t[1] < t[2] && t[1] < t[0])
		swap(a, "sa\n");
	else if (t[0] > t[1] && t[1] < t[2] && t[2] > t[0])
		rotate(a, "ra\n");
	else if (t[0] < t[1] && t[1] > t[2] && t[2] > t[0])
		reverse_rotate(a, "rra\n");
	else if (t[0] < t[1] && t[1] > t[2] && t[2] < t[0])
	{
		swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	else if (t[0] < t[1] && t[1] < t[2] && t[2] > t[0])
	{
		swap(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
}

void	sort_5_norm(t_stack *a, t_stack *b, int min, int i)
{
	if (a->arr[a->top - 2] == min)
	{
		rotate(a, "ra\n");
		swap(a, "sa\n");
		push_top(a, b, "pb\n");
	}
	else if (a->arr[a->top - 3] == min)
	{
		if (i == 0)
		{
			reverse_rotate(a, "rra\n");
			reverse_rotate(a, "rra\n");
		}
		else
			reverse_rotate(a, "rra\n");
		push_top(a, b, "pb\n");
	}
	else if (a->arr[a->top - 4] == min)
	{
		reverse_rotate(a, "rra\n");
		push_top(a, b, "pb\n");
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	i;
	int	min;

	i = -1;
	while (++i < 2)
	{
		min = is_get_min(a);
		if (a->arr[a->top] == min)
			push_top(a, b, "pb\n");
		else if (a->arr[a->top - 1] == min)
		{
			swap(a, "sa\n");
			push_top(a, b, "pb\n");
		}
		sort_5_norm(a, b, min, i);
	}
	sort_3(a);
	push_top(b, a, "pa\n");
	push_top(b, a, "pa\n");
}
