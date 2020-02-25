/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:24 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/25 20:06:13 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_best_to_top(t_stack *stack, int i)
{
	while (i && i > stack->b_size / 2 + 1 && i++ < stack->b_size)
	{
		reverse_rotate(stack->b);
		ft_printf("rrb\n");
	}
	while (i && --i < stack->b_size && stack->b)
	{
		rotate(stack->b);
		ft_printf("rb\n");
	}
}

void	find_biggest(t_stack *stack)
{
	int		i;
	t_node	*temp;
	t_node	*temp2;

	i = 0;
	temp = stack->b->next;
	temp2 = stack->b;
	while (i < stack->b_size)
	{
		if (temp->data > temp2->data)
			i++;
		else
			break ;
		temp = temp->next;
		temp2 = temp2->next;
	}
	rotate_best_to_top(stack, i);
}

void	empty_stack(t_stack *stack)
{
	find_biggest(stack);
	while (stack->b_size)
	{
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
		ft_printf("pa\n");
	}
}
