/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:10:30 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:31 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack, char *s)
{
	if (stack->top == 0 || stack->top == -1)
		return ;
	ft_swap(&stack->arr[stack->top], &stack->arr[stack->top - 1]);
	if (!s)
		return ;
	ft_putstr(s);
}

void	push_top(t_stack *stack1, t_stack *stack2, char *s)
{
	if (stack1->top == -1)
		return ;
	stack2->arr[++stack2->top] = stack1->arr[stack1->top--];
	if (!s)
		return ;
	ft_putstr(s);
}

void	rotate(t_stack *stack, char *s)
{
	int	tmp ;
	int	i;

	tmp = stack->arr[stack->top];
	i = stack->top + 1;
	while (--i)
	{
		stack->arr[i] = stack->arr[i - 1];
	}
	stack->arr[0] = tmp;
	if (!s)
		return ;
	ft_putstr(s);
}

void	reverse_rotate(t_stack *stack, char *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->arr[0];
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->top] = tmp;
	if (!s)
		return ;
	ft_putstr(s);
}

void	two_moves(t_stack *a, t_stack *b, int n, char *s)
{
	if (n == 1)
	{
		reverse_rotate(a, 0);
		reverse_rotate(b, 0);
	}
	else if (n == 2)
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (n == 3)
	{
		swap(a, 0);
		swap(b, 0);
	}
	if (!s)
		return ;
	ft_putstr(s);
}
