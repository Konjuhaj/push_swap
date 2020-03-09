/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/09 15:31:46 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_dots(int num)
{
	while (num--)
		ft_printf(".");
}

void	print_numbers(int num)
{
	ft_printf("%d", num);
}

void	print_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack->a == NULL? NULL : stack->a->next;
	temp2 = stack->b == NULL? NULL : stack->b->next;
	stack->a == NULL ? ft_printf("%d", stack->a->data) : 0;
	ft_printf("	|	");
	stack->b == NULL ? ft_printf("%d", stack->b->data) : 0;
	ft_printf("\n");
	while (temp2 != stack->b || temp != stack->a)
	{
		if (temp != stack->a)
		{
			stack->visual == 'v' ? print_numbers(temp->data) : 0;
			stack->visual == 'l' ? print_dots(temp->data) : 0;
			temp = temp->next;
		}
		ft_printf("	|	");
		if (temp2 != stack->b)
		{
			stack->visual == 'v' ? print_numbers(temp->data) : 0;
			stack->visual == 'l' ? print_dots(temp->data) : 0;
			temp2 = temp2->next;
		}
		ft_printf("\n");
	}
}
