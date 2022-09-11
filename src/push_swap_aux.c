/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:19:13 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/28 13:06:02 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_indexs(t_stack *stack_a)
{
	int				index;
	size_t			i;
	size_t			j;
	t_double_list	*ptr;
	t_double_list	*ptr2;

	i = 1;
	ptr = stack_a->lst;
	while (i <= stack_a->len)
	{
		j = 1;
		index = 1;
		ptr2 = ptr;
		while (j <= stack_a->len - 1)
		{
			ptr2 = ptr2->next;
			if (ptr->number > ptr2->number)
				index++;
			j++;
		}
		ptr->index = index;
		ptr = ptr->next;
		i++;
	}
}

size_t	min_pos(t_stack *stack_a)
{
	size_t	i;
	int		minimum_pos;
	t_stack	*tmp;
	int		num;

	tmp = stack_a;
	i = 0;
	minimum_pos = i;
	num = tmp->lst->number;
	while (i < tmp->len)
	{
		if (tmp->lst->number < num)
		{
			minimum_pos = i;
			num = tmp->lst->number;
		}
		tmp->lst = tmp->lst->next;
		i++;
	}
	return (minimum_pos);
}

size_t	max_pos(t_stack *stack_a)
{
	size_t	i;
	int		max_pos;
	t_stack	*tmp;
	int		num;

	tmp = stack_a;
	i = 0;
	max_pos = i;
	num = tmp->lst->number;
	while (i < tmp->len)
	{
		if (tmp->lst->number > num)
		{
			max_pos = i;
			num = tmp->lst->number;
		}
		tmp->lst = tmp->lst->next;
		i++;
	}
	return (max_pos);
}

int	strlen_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	clear_list(t_stack *stack)
{
	free_whole_list(stack->lst, stack->len);
	print_error();
}
