/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:34:43 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/27 12:58:17 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	stack->lst = stack->lst->prev;
}

void	rra(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_reverse_rotate(stack_a);
	stack_b->len = stack_b->len;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_reverse_rotate(stack_b);
	stack_a->len = stack_a->len;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
