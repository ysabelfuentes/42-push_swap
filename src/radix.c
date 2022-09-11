/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:55:27 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/19 17:03:54 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_stack *a, size_t stack_size)
{
	t_double_list	*is_sort;
	t_double_list	*tmp;
	size_t			i;
	int				sort;

	i = 1;
	sort = 1;
	is_sort = a->lst;
	tmp = a->lst->next;
	while (stack_size > i)
	{
		if (is_sort->number > tmp->number)
			sort = 0;
		is_sort = tmp;
		tmp = tmp->next;
		i++;
	}
	return (sort);
}

void	stk_mv_radix(t_stack *a, t_stack *b, int max_size, int bit_pos)
{
	size_t	size;
	int		num;

	size = max_size;
	b->lst = NULL;
	while (size)
	{
		num = a->lst->index;
		if ((num >> bit_pos) & 1)
			ra(a, b, 1);
		else
			pb(a, b, 1);
		size--;
	}
}

void	radix(t_stack **a)
{
	int		bit_pos;
	t_stack	*b;

	bit_pos = 0;
	b = malloc(sizeof(t_stack));
	if (b)
	{
		b->len = 0;
		b->lst = NULL;
		while (!check_sort(*a, (*a)->len))
		{
			stk_mv_radix(*a, b, (*a)->len, bit_pos);
			while (b->lst != NULL)
				pa(*a, b, 1);
			bit_pos++;
		}
		free(b);
	}
}
