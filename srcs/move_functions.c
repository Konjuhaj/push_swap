/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:56:13 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 22:14:17 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_node *top_node)
{
	t_node	*temp;
	t_node	*next;
	int		num;

	temp = top_node;
	next = top_node->next;
	while (temp->next != top_node)
	{
		num = temp->data;
		temp->data = next->data;
		next->data = num;
		next = next->next;
		temp = temp->next;
	}
}

void	reverse_rotate(t_node *top_node)
{
	t_node	*temp;
	t_node	*previous;
	int		num;

	temp = top_node;
	previous = top_node->previous;
	while (temp->previous != top_node)
	{
		num = temp->data;
		temp->data = previous->data;
		previous->data = num;
		previous = previous->previous;
		temp = temp->previous;
	}
}

void	swap(t_node *top_node)
{
	t_node	*next;
	int		num;

	next = top_node->next;
	num = next->data;
	next->data = top_node->data;
	top_node->data = num;
}

t_node	*detach_node(t_node **src)
{
	t_node *temp;

	temp = (*src)->next;
	temp->previous = (*src)->previous;
	temp = (*src)->previous;
	temp->next = (*src)->next;
	return(*src);
}

void	push(t_node **dest, int *dest_size, t_node **src, int *src_size)
{
	t_node *temp;
	t_node *b_head;
	t_node *old_head;

	b_head = detach_node(src);
	old_head = b_head->next;
	if (*dest_size == 0)
	{
		*dest = *src;
		(*dest)->next = *dest;
		(*dest)->previous = *dest;
	}
	else
	{
		b_head->next = *dest;
		b_head->previous = (*dest)->previous;
		temp = (*dest)->previous;
		temp->next = b_head;
		temp = (*dest)->next;
		temp->previous = b_head;
		*dest = b_head;
	}
	*src = old_head;
	if (++*dest_size && --*src_size == 0)
		src = NULL;
}