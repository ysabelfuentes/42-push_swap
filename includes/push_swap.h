/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:05:46 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/28 13:06:14 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_double_list
{
	int						number;
	int						index;
	struct s_double_list	*prev;
	struct s_double_list	*next;
}							t_double_list;

typedef struct s_stack
{
	size_t					len;
	t_double_list			*lst;
}							t_stack;

void	*new_node(int number);
void	insert_before(t_double_list *list, t_double_list *node);
void	insert_after(t_double_list *list, t_double_list *node);
void	free_node(t_double_list *node);
void	free_whole_list(t_double_list *list, size_t len);
void	clear_list(t_stack *stack);
void	check_args(int argc, char **argv, int split);
void	print_error(void);
int		strlen_split(char **split);
bool	is_already_sorted(t_double_list *list, size_t len);
void	init_stacks_split(t_stack *a, t_stack *b, int argc, char **split);
void	init_stacks(t_stack *a, t_stack *b, int argc, char **argv);
void	sa(t_stack *stack_a, t_stack *stack_b, int print);
void	sb(t_stack *stack_a, t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
void	ra(t_stack *stack_a, t_stack *stack_b, int print);
void	rb(t_stack *stack_a, t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);
void	rra(t_stack *stack_a, t_stack *stack_b, int print);
void	rrb(t_stack *stack_a, t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);
void	fill_indexs(t_stack *stack_a);
size_t	min_pos(t_stack *stack_a);
size_t	max_pos(t_stack *stack_a);
void	sort_3_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_4_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);
void	radix(t_stack **a);
void	stk_mv_radix(t_stack *a, t_stack *b, int max_size, int bit_pos);
int		check_sort(t_stack *a, size_t stack_size);
void	print_list(t_double_list *list, size_t len);

#endif