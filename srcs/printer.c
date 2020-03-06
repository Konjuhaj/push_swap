/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/28 10:28:31 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack->a == NULL? NULL : stack->a->next;
	temp2 = stack->b == NULL? NULL : stack->b->next;
	if (stack->a)
		ft_printf("%d->(%d > %d > %d)", stack->a->data, stack->a->distance_to_top, stack->a->distance_in_a, stack->a->price);
	ft_printf("	|	");
	if (stack->b)
		ft_printf("%d->(%d > %d > %d)", stack->b->data, stack->b->distance_to_top, stack->b->distance_in_a, stack->b->price);
	ft_printf("\n");
	while (temp2 != stack->b || temp != stack->a)
	{
		if (temp != stack->a)
		{
			ft_printf("%d->(%d > %d > %d)", temp->data, temp->distance_to_top, temp->distance_in_a, temp->price);
			temp = temp->next;
		}
		ft_printf("	|	");
		if (temp2 != stack->b)
		{
			ft_printf("%d->(%d > %d > %d)", temp2->data, temp2->distance_to_top, temp2->distance_in_a, temp2->price);
			temp2 = temp2->next;
		}
		ft_printf("\n");
	}
}
