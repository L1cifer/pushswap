/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:08:55 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:08:57 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "gnl/get_next_line.h"
# include "../push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	spaces_count(char *av);
int		spaces_check(char **av);
char	**array_split(int ac, char **av);
char	**array_filling(int ac, char **av, int *i);
t_stack	*create_stack(unsigned int size);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
void	push(t_stack *stack, int item);
void	swap(t_stack *stack, char *s);
void	push_top(t_stack *stack1, t_stack *stack2, char *s);
void	rotate(t_stack *stack, char *s);
void	reverse_rotate(t_stack *stack, char *s);
void	two_moves(t_stack *a, t_stack *b, int n, char *s);
void	ft_check_moves(t_stack *a, t_stack *b, char *move);
int		ft_strcmp(char *s1, char *s2);
int		is_sorted(t_stack *a);

#endif