/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:53:55 by yfuentes          #+#    #+#             */
/*   Updated: 2022/08/01 12:54:00 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_already_sorted(t_double_list *list, size_t len)
{
	size_t	i;

	i = 0;
	while (++i < len)
	{
		if (list->number > list->next->number)
			return (false);
		list = list->next;
	}
	return (true);
}

void	init_stacks_split(t_stack *a, t_stack *b, int argc, char **split)
{
	a->len = 1;
	a->lst = new_node((int)ft_long_atoi(split[--argc]));
	if (!a->lst)
		print_error();
	a->lst->prev = a->lst;
	a->lst->next = a->lst;
	b->len = 0;
	b->lst = NULL;
	while (--argc >= 0)
	{
		a->len++;
		insert_before(a->lst, new_node((int)ft_long_atoi(split[argc])));
		if (a->lst->prev)
			a->lst = a->lst->prev;
		else
		{
			clear_list(a);
			print_error();
		}
	}
	free(*split);
}

void	init_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	a->len = 1;
	a->lst = new_node((int)ft_long_atoi(argv[--argc]));
	if (!a->lst)
		print_error();
	a->lst->prev = a->lst;
	a->lst->next = a->lst;
	b->len = 0;
	b->lst = NULL;
	while (--argc)
	{
		a->len++;
		insert_before(a->lst, new_node((int)ft_long_atoi(argv[argc])));
		if (a->lst->prev)
			a->lst = a->lst->prev;
		else
		{
			clear_list(a);
			print_error();
		}
	}
}
