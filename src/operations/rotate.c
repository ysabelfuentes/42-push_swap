/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:44:24 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/27 12:58:25 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	stack->lst = stack->lst->next;
}

void	ra(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_rotate(stack_a);
	stack_b->len = stack_b->len;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_rotate(stack_b);
	stack_a->len = stack_a->len;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (print)
		write(1, "rr\n", 4);
}
