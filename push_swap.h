/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:11:00 by atakeddi          #+#    #+#             */
/*   Updated: 2022/05/22 18:11:01 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX 2147483647
# define MIN -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack {
	int				*arr;
	int				top;
	unsigned int	capacity;
}	t_stack;

int			ft_isdigit(int c);
int			duplicate(char **arr);
size_t		ft_strlen(const char *s);
char		*ft_putstr(char *str);
void		ft_swap(int *a, int *b);
long long	ft_atoi(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		print_error(void);
size_t		spaces_count(char *av);
int			spaces_check(char **av);
char		**array_split(int ac, char **av);
char		**array_filling(int ac, char **av, int *i);
t_stack		*create_stack(unsigned int size);
int			is_full(t_stack *stack);
void		push(t_stack *stack, int item);
void		swap(t_stack *stack, char *s);
void		push_top(t_stack *stack1, t_stack *stack2, char *s);
void		rotate(t_stack *stack, char *s);
void		reverse_rotate(t_stack *stack, char *s);
void		two_moves(t_stack *a, t_stack *b, int n, char *s);
void		small_num_sort(t_stack *a,	t_stack *b, int n);
void		sort_2(t_stack *a);
void		sort_3(t_stack *a);
void		sort_5(t_stack *a, t_stack *b);
void		sort_5_norm(t_stack *a, t_stack *b, int min, int i);
int			get_index(t_stack *stack, int m);
void		from_a_to_b(t_stack *a, t_stack *b, int nb);
int			is_in_arr(int *arr, int n, int size);
int			get_max_array(int *arr, int size);
int			*get_flags(int *t, t_stack *a);
int			get_head(t_stack *a, int i, int j);
int			*longest_list(t_stack *a, int *p);
int			circle_in_list(t_stack *stack, int n);
void		push_from_a_to_b(t_stack *a, t_stack *b);
int			get_min_index(int *arr, int size);
int			is_get_min(t_stack *a);
int			get_next_nb(t_stack *a, int nb);
int			get_position(t_stack *a, t_stack *b, int nb, int next_nb);
int			best_nb(t_stack *a, t_stack *b, int nb, int next_nb);
int			nb_stack(t_stack *a, t_stack *b);
int			get_index_max(int *arr, int size, int n);
void		push_to_stack_a(t_stack *a, t_stack *b, int nb, int next_nb);
void		sort_b_to_a(t_stack *a, t_stack *b);
void		ft_freee(t_stack *a, t_stack *b);

#endif