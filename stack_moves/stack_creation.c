/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:10:36 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:37 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->arr = malloc(sizeof(int) * size);
	stack->capacity = size;
	stack->top = -1;
	return (stack);
}

int	is_full(t_stack *stack)
{
	return (stack->top == (int)stack->capacity - 1);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

void	push(t_stack *stack, int item)
{
	if (is_full(stack))
		return ;
	stack->arr[++stack->top] = item;
}
