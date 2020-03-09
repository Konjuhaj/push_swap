/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/09 16:41:19 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_dots(int num)
{
	int i;

	i = ft_abs(num);
	while (i--)
	{
		if (num < 0)
			ft_printf("%s%s%s", YELLOW, ".", RESET);
		else
			ft_printf(".");
	}
}

void	print_numbers(int num)
{
	ft_printf("%d", num);
}

void	print_stack(t_stack *stack)
{
	int i;

	i = -1;
	while (++i < stack->a_size || i < stack->b_size)
	{
		if (i < stack->a_size)
		{
			stack->visual == 'v' ? print_numbers(stack->a->data) : 0;
			stack->visual == 'l' ? print_dots(stack->a->data) : 0;
			stack->a = stack->a->next;
		}
		ft_printf("	|	");
		if (i < stack->b_size)
		{
			stack->visual == 'v' ? print_numbers(stack->b->data) : 0;
			stack->visual == 'l' ? print_dots(stack->b->data) : 0;
			stack->b = stack->b->next;
		}
		ft_printf("\n");
	}
}
