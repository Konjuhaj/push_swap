/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 11:17:51 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	t_node *temp;
	t_node *temp2;

	temp = stack->a;
	temp2 = stack->b;
	while (temp)
	{
		ft_printf("%d", temp->data);
		temp = temp->next;
		if(temp2)
			ft_printf("		%d", temp2->data);
		ft_printf("\n");
		if (temp == stack->a)
			break ;
	}
}
