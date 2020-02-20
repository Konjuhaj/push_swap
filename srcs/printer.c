/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/20 18:12:20 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	t_node *temp;

	temp = stack->a;
	while (temp)
	{
		ft_printf("%d\n", temp->data);
		temp = temp->next;
		// if (temp == stack->a)
		// 	break ;
	}
}
