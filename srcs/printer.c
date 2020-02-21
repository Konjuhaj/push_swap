/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 22:24:29 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack->a->next;
	temp2 = stack->b->next;
	ft_printf("%d	%d\n", stack->a->data, stack->b->data);
	while (temp2 != stack->b || temp != stack->a)
	{
		if (temp != stack->a)
		{
			ft_printf("%d", temp->data);
			temp = temp->next;
		}
		ft_printf("	");
		if (temp2 != stack->b)
		{
			ft_printf("%d", temp2->data);
			temp2 = temp2->next;
		}
		ft_printf("\n");
	}
}
