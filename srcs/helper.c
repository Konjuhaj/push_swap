/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:24 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/27 10:32:34 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_best_to_top(t_stack *stack, int i)
{
	ft_printf("	->%d\n");
	while (i && i > stack->b_size / 2 && i++ < stack->b_size)
	{
		reverse_rotate(stack->b);
		ft_printf("rrb\n");
	}
	while (i && --i < stack->b_size / 2)
	{
		rotate(stack->b);
		ft_printf("rb\n");
	}
}

void	sort_three(t_node *node)
{
	t_node *next;
	t_node *prev;

	next = node->next;
	prev = node->previous;
	while ((is_sorted(node)))
	{
		if (node->data < next->data && node->data > prev->data && (reverse_rotate(node)))
			ft_printf("rra\n");
		else if (prev->data > next->data && prev->data < node->data && (rotate(node)))
			ft_printf("ra\n");
		else if (swap(node))
			ft_printf("sa\n");
	}
}

void	empty_stack(t_stack *stack)
{
	rotate_best_to_top(stack, find_biggest(stack->b, stack->b_size) + 1);
	while (stack->b_size)
	{
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
		ft_printf("pa\n");
	}
}
