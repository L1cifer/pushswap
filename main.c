/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:10:43 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:44 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**arr;
	int		i;
	int		n;
	t_stack	*a;
	t_stack	*b;

	arr = array_filling(ac, av, &i);
	n = i;
	a = create_stack(i);
	b = create_stack(i);
	i = i - 1;
	while (i >= 0)
		push(a, ft_atoi(arr[i--]));
	if (n == 1 || n == 2 || n == 3 || n == 5)
		small_num_sort(a, b, n);
	else
	{
		push_from_a_to_b(a, b);
		sort_b_to_a(a, b);
	}
	ft_freee(a, b);
}
