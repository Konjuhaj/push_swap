/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/09 19:01:12 by bkonjuha         ###   ########.fr       */
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
			ft_printf("%c %s", '.', RESET);
	}
}

void	print_numbers(int i)
{
	ft_printf("%d %s", i, RESET);
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
			data = stack->visual == 'l' ? stack->a->data : ncount(stack->a->data) + 1;
			set_color(stack->a, stack->a->next, stack->color);
			stack->visual == 'v' ? print_numbers(stack->a->data) : 0;
			stack->visual == 'l' ? print_dots(stack->a->data) : 0;
			stack->a = stack->a->next;
		}
		ft_printf("%*c|	", 160 - ft_abs(data), 0 );
		if (i < stack->b_size)
		{
			set_color(stack->b, stack->b->next, stack->color);
			stack->visual == 'v' ? print_numbers(stack->b->data) : 0;
			stack->visual == 'l' ? print_dots(stack->b->data) : 0;
			stack->b = stack->b->next;
		}
		ft_printf("\n");
	}
}
