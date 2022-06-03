/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:09:24 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:09:26 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_freee(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
}
