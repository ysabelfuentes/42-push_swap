/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:50:16 by yfuentes          #+#    #+#             */
/*   Updated: 2022/08/01 12:53:00 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	exec_operation(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (false);
	return (true);
}

static void	check_operation(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		exec_operation(op, stack_a, stack_b);
		free(op);
		op = get_next_line(0);
	}
	if (is_already_sorted(stack_a->lst, stack_a->len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**split;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		argc = strlen_split(split);
		if (argc == 1)
			return (0);
		check_args(argc, split, 1);
		init_stacks_split(&stack_a, &stack_b, argc, split);
	}
	else
	{
		check_args(argc, argv, 0);
		init_stacks(&stack_a, &stack_b, argc, argv);
	}
	check_operation(&stack_a, &stack_b);
	free_whole_list(stack_a.lst, stack_a.len);
}

/* 	system("leaks -q checker"); */