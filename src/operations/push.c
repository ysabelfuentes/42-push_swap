/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:11:56 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/27 12:58:09 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_double_list	*ft_get_top_node(t_stack *stack)
{
	t_double_list	*top_elem;

	top_elem = stack->lst;
	if (stack->len == 1)
		stack->lst = NULL;
	else
	{
		stack->lst = stack->lst->next;
		stack->lst->prev = stack->lst->prev->prev;
		stack->lst->prev->next = stack->lst;
	}
	top_elem->next = top_elem;
	top_elem->prev = top_elem;
	return (top_elem);
}

static void	ft_push(t_stack *to, t_stack *from)
{
	t_double_list	*elem;

	if (!from->len)
		return ;
	elem = ft_get_top_node(from);
	if (to->len == 0)
		to->lst = elem;
	else
	{
		elem->next = to->lst;
		elem->prev = to->lst->prev;
		to->lst->prev->next = elem;
		to->lst->prev = elem;
		to->lst = to->lst->prev;
	}
	from->len--;
	to->len++;
}

void	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_push(stack_a, stack_b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	ft_push(stack_b, stack_a);
	if (print)
		write(1, "pb\n", 3);
}
