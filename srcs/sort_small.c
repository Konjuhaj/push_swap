/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:53:14 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 11:53:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_stack *stack)
{
	t_node *temp;
	t_node *next;

	temp = stack->a;
	next = stack->a->next;
	while (temp->next != stack->a)
	{
		if (temp->data > next->data)
			return (1);
		temp = temp->next;
		next = next->next;
	}
	return (0);
}

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

int		smallest_node(t_node *a)
{
	t_node *next;
	t_node *previous;

	next = a->next;
	previous = a->previous;
	if (a->data < next->data && a->data < previous->data)
		return (0);
	else if(next->data < a->data && next->data < previous->data)
		return (1);
	else
		return (-1);
}

void	sort_small(t_stack *stack)
{
	int movable_node;
	if (is_sorted(stack))
	{
		movable_node = smallest_node(stack->a);
		reverse_rotate(stack->a);
		swap(stack->a);
	}
	ft_printf("SORTED\n");
}

