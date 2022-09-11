/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:54:42 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/27 12:58:33 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->len <= 1)
		return ;
	tmp = stack->lst->next->number;
	stack->lst->next->number = stack->lst->number;
	stack->lst->number = tmp;
}

void	sa(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_swap(stack_a);
	stack_b->len = stack_b->len;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_swap(stack_b);
	stack_a->len = stack_a->len;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}
