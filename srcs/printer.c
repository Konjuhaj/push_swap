/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 14:33:29 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;
	int		stopper;

	temp = stack->a;
	temp2 = stack->b;
	stopper = 1;
	while (temp)
	{
		ft_printf("%d	", temp->data);
		temp = temp->next;
		if(temp2 && stopper)
		{
			ft_printf("%d", temp2->data);
			if (temp2->next == stack->b)
				stopper--;
		}
		ft_printf("\n");
		if (temp == stack->a)
			break ;
	}
}
