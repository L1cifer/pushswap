/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:10:22 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:23 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_position(t_stack *a, t_stack *b, int nb, int next_nb)
{
	int	index;
	int	next_nb_index;
	int	arr[3];

	index = get_index(b, nb);
	next_nb_index = get_index(a, next_nb);
	if (index >= b->top / 2)
		arr[0] = b->top - index;
	else
		arr[0] = index + 1;
	if (next_nb_index >= a->top / 2)
		arr[0] += a->top - next_nb_index;
	else
		arr[0] += next_nb_index + 1;
	if (index + 1 > next_nb_index + 1)
		arr[1] = index + 1;
	else
		arr[1] = next_nb_index + 1;
	if (b->top - index > a->top - next_nb_index)
		arr[2] = b->top - index;
	else
		arr[2] = a->top - next_nb_index;
	return (get_min_index(arr, 3));
}

int	best_nb(t_stack *a, t_stack *b, int nb, int next_nb)
{
	int	index;
	int	next_nb_index;
	int	arr[3];

	index = get_index(b, nb);
	next_nb_index = get_index(a, next_nb);
	if (index >= b->top / 2)
		arr[0] = b->top - index;
	else
		arr[0] = index + 1;
	if (next_nb_index >= a->top / 2)
		arr[0] += a->top - next_nb_index;
	else
		arr[0] += next_nb_index + 1;
	if (index + 1 > next_nb_index + 1)
		arr[1] = index + 1;
	else
		arr[1] = next_nb_index + 1;
	if (b->top - index > a->top - next_nb_index)
		arr[2] = b->top - index;
	else
		arr[2] = a->top - next_nb_index;
	return (arr[get_min_index(arr, 3)]);
}

int	nb_stack(t_stack *a, t_stack *b)
{
	int	*list;
	int	index;
	int	next_nb;
	int	i;

	list = (int *)ft_calloc(b->top + 1, sizeof(int));
	if (!list)
		exit (1);
	index = 0;
	i = 0;
	while (i < b->top + 1)
	{
		next_nb = get_next_nb(a, b->arr[i]);
		list[i] = best_nb(a, b, b->arr[i], next_nb);
		if (list[i] <= list[index])
			index = i;
		i++;
	}
	free (list);
	return (b->arr[index]);
}

void	push_to_stack_a(t_stack *a, t_stack *b, int nb, int next_nb)
{
	int	p;

	p = get_position(a, b, nb, next_nb);
	if (p == 1)
		while (a->arr[a->top] != next_nb && b->arr[b->top] != nb)
			two_moves(a, b, 1, "rrr\n");
	else if (p == 2)
		while (a->arr[a->top] != next_nb && b->arr[b->top] != nb)
			two_moves(a, b, 2, "rr\n");
	while (a->arr[a->top] != next_nb)
	{
		if (get_index(a, next_nb) >= a->top / 2)
			rotate(a, "ra\n");
		else
			reverse_rotate(a, "rra\n");
	}
	while (b->arr[b->top] != nb)
	{
		if (get_index(b, nb) >= b->top / 2)
			rotate(b, "rb\n");
		else
			reverse_rotate(b, "rrb\n");
	}
	push_top(b, a, "pa\n");
}

void	sort_b_to_a(t_stack *a, t_stack *b)
{
	int	nb;
	int	next_nb;
	int	min;

	while (b->top >= 0)
	{
		nb = nb_stack(a, b);
		next_nb = get_next_nb(a, nb);
		push_to_stack_a(a, b, nb, next_nb);
	}
	min = is_get_min(a);
	while (a->arr[a->top] != min)
	{
		if (get_index(a, min) >= a->top / 2)
			rotate(a, "ra\n");
		else
			reverse_rotate(a, "rra\n");
	}
}
