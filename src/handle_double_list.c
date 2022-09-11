/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:09:18 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/28 12:52:55 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*new_node(int number)
{
	t_double_list	*new;

	new = malloc(sizeof(t_double_list));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->number = number;
	new->index = 0;
	return (new);
}

void	insert_before(t_double_list *list, t_double_list *node)
{
	if (!list || !node)
		return ;
	node->prev = list->prev;
	node->next = list;
	if (node->prev)
		node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

void	insert_after(t_double_list *list, t_double_list *node)
{
	if (!list || !node)
		return ;
	node->prev = list;
	node->next = list->next;
	if (node->prev)
		node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

void	free_node(t_double_list *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
}

void	free_whole_list(t_double_list *list, size_t len)
{
	if (!list)
		return ;
	while (len--)
		free_node(list->next);
}
