/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:09:04 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:09:07 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_stack *a)
{
	int	i;
	int	nb;

	i = 0;
	nb = a->arr[i];
	while (i <= a->top)
	{
		if (nb < a->arr[i])
			return (0);
		nb = a->arr[i];
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_check_moves(t_stack *a, t_stack *b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		swap(a, 0);
	else if (!ft_strcmp(move, "sb\n"))
		swap(b, 0);
	else if (!ft_strcmp(move, "ra\n"))
		rotate(a, 0);
	else if (!ft_strcmp(move, "rb\n"))
		rotate(b, 0);
	else if (!ft_strcmp(move, "rra\n"))
		reverse_rotate(a, 0);
	else if (!ft_strcmp(move, "rrb\n"))
		reverse_rotate(b, 0);
	else if (!ft_strcmp(move, "pa\n"))
		push_top(b, a, 0);
	else if (!ft_strcmp(move, "pb\n"))
		push_top(a, b, 0);
	else if (!ft_strcmp(move, "rrr\n"))
		two_moves(a, b, 1, 0);
	else if (!ft_strcmp(move, "rr\n"))
		two_moves(a, b, 2, 0);
	else if (!ft_strcmp(move, "ss\n"))
		two_moves(a, b, 3, 0);
	else
		print_error();
}

int	main(int ac, char **av)
{
	int		i;
	char	**arr;
	char	*move;
	t_stack	*a;
	t_stack	*b;

	arr = array_filling(ac, av, &i);
	a = create_stack(i);
	b = create_stack(i);
	i = i - 1;
	while (i >= 0)
		push(a, ft_atoi(arr[i--]));
	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		ft_check_moves(a, b, move);
		free(move);
	}
	if (is_sorted(a) && is_empty(b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
