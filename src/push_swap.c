/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:05:22 by yfuentes          #+#    #+#             */
/*   Updated: 2022/08/01 12:54:10 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (is_already_sorted(stack_a.lst, stack_a.len))
		return (0);
	sort_stacks(&stack_a, &stack_b);
	free_whole_list(stack_a.lst, stack_a.len);
	return (0);
}

/*system("leaks -q push_swap");*/
/* void	print_list(t_double_list *list, size_t len)
{
	size_t	i;

	if (!list)
		return ;
	i = 0;
	while (i < len)
	{
		printf("num = %d\n", list->number);
		printf("index = %d\n", list->index);
		list = list->next;
		i++;
	}
}
 */