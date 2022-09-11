/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:09:52 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/27 13:08:23 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_1;
	int	pos_2;
	int	last_pos;

	pos_1 = stack_a->lst->number;
	pos_2 = stack_a->lst->next->number;
	last_pos = stack_a->lst->next->next->number;
	if (pos_1 > pos_2 && pos_2 > last_pos)
	{
		sa(stack_a, stack_b, 1);
		rra(stack_a, stack_b, 1);
	}
	else if (pos_2 > last_pos && pos_1 < last_pos)
	{
		sa(stack_a, stack_b, 1);
		ra(stack_a, stack_b, 1);
	}
	else if (last_pos < pos_2 && pos_1 < pos_2)
		rra(stack_a, stack_b, 1);
	else if (pos_1 > pos_2 && pos_1 < last_pos)
		sa(stack_a, stack_b, 1);
	else if (pos_1 > pos_2 && pos_2 < last_pos)
		ra(stack_a, stack_b, 1);
}

void	sort_4_numbers(t_stack *stack_a, t_stack *stack_b)
{
	size_t	pos;

	pos = min_pos(stack_a);
	if (pos == 1)
		sa(stack_a, stack_b, 1);
	else if (pos == 2)
	{
		ra(stack_a, stack_b, 1);
		ra(stack_a, stack_b, 1);
	}
	else if (pos == 3)
	{
		rra(stack_a, stack_b, 1);
	}
	pb(stack_a, stack_b, 1);
	sort_3_numbers(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}

void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b)
{
	size_t	pos;

	pos = max_pos(stack_a);
	while (pos > 0)
	{
		ra(stack_a, stack_b, 1);
		pos--;
	}
	pb(stack_a, stack_b, 1);
	sort_4_numbers(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
	ra(stack_a, stack_b, 1);
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
		sa(stack_a, stack_b, 1);
	if (stack_a->len == 3)
		sort_3_numbers(stack_a, stack_b);
	if (stack_a->len == 4)
		sort_4_numbers(stack_a, stack_b);
	if (stack_a->len == 5)
		sort_5_numbers(stack_a, stack_b);
	else
	{
		fill_indexs(stack_a);
		radix(&stack_a);
	}
}
