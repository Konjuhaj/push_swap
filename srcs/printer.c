/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/14 00:07:48 by bkonjuha         ###   ########.fr       */
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
			ft_printf("%s%s", YELLOW, ".");
		else
			ft_printf("%c", '.');
	}
	ft_printf(RESET);
}

void	print_numbers(int i)
{
	ft_printf("%d%s", i, RESET);
}

void	set_color(t_node *curr, t_node *next, int color)
{
	if (color)
	{
		if ((curr->data > next->data))
			ft_printf(RED);
		else
			ft_printf(GREEN);
	}
}

void	print_stack(t_stack *stack)
{
	int i;
	int data;

	i = -1;
	while (++i < stack->a_size || i < stack->b_size)
	{
		data = 0;
		if (i < stack->a_size)
		{
			data = stack->flag == 'l' ? stack->a->data : ncount(stack->a->data);
			set_color(stack->a, stack->a->next, stack->color);
			stack->flag == 'v' ? print_numbers(stack->a->data) : 0;
			stack->flag == 'l' ? print_dots(stack->a->data) : 0;
			stack->a = stack->a->next;
		}
		ft_printf("%*c ", (80 - ft_abs(data)), '|');
		if (i < stack->b_size)
		{
			set_color(stack->b, stack->b->next, stack->color);
			stack->flag == 'v' ? print_numbers(stack->b->data) : 0;
			stack->flag == 'l' ? print_dots(stack->b->data) : 0;
			stack->b = stack->b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-------\n");
}
