/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:18:56 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/07 10:47:41 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		top_down_greater_than(t_node *node, int size, int num, int id)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (num > node->data && id == DESENNDING)
			break ;
		else if (num < node->data && id == ASCENDING)
			break ;
		node = node->next;
	}
	// ft_printf("tdgt %d\n", i);
	return (i);
}

int		bottom_up_smaller_than(t_node *node, int size, int num, int id)
{
	int i;

	i = size;
	node = node->previous;
	while (i > 0)
	{
		if (num < node->data && id == DESENNDING)
			break ;
		else if (num > node->data && id == ASCENDING)
			break ;
		node = node->previous;
		i--;
	}
	// ft_printf("bust %d\n", i);
	return (i);
}

int	find_biggest(t_node *node, int size, int id)
{
	int		i;
	t_node	*next;
	t_node	*current;

	i = 1;
	next = node->next;
	current = node;
	while (i <= size)
	{
		if (next->data < current->data && id == DESENNDING)
			i++;
		else if (next->data > current->data && id == ASCENDING)
			i++;
		else
			break ;
		next = next->next;
		current = current->next;
	}
	if (next == node)
		i = 0;
	// ft_printf("fb %d\n", i);
	return (i);
}
