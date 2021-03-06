/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:24 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/14 00:07:48 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_best_to_top(t_node **node, int i, int size, char letter)
{
	while (i && i > (size / 2) && i < size)
	{
		reverse_rotate(node);
		ft_printf("rr%c\n", letter);
		i++;
	}
	while (i && --i < (size / 2))
	{
		rotate(node);
		ft_printf("r%c\n", letter);
	}
}

void	sort_three(t_node **node)
{
	t_node *next;
	t_node *prev;

	while ((is_sorted(*node)))
	{
		next = (*node)->next;
		prev = (*node)->previous;
		if ((*node)->data < next->data
			&& (*node)->data > prev->data && (reverse_rotate(node)))
			ft_printf("rra\n");
		else if (prev->data > next->data
			&& prev->data < (*node)->data && (rotate(node)))
			ft_printf("ra\n");
		else if (swap(node))
			ft_printf("sa\n");
	}
}

void	embty_b_stack(t_stack *stack)
{
	int move;

	move = find_biggest(stack->b, stack->b_size, DESENNDING);
	rotate_best_to_top(&stack->b, move, stack->b_size, 'b');
	while (stack->b_size)
	{
		stack->flag ? print_stack(stack) : 0;
		move = find_best_spot(stack->b->data, stack->a,
								stack->a_size, ASCENDING);
		rotate_best_to_top(&stack->a, move, stack->a_size, 'a');
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
		ft_printf("pa\n");
	}
}
