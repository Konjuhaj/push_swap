/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:53:14 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/04 10:17:57 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_node *stack)
{
	t_node *temp;
	t_node *next;

	temp = stack;
	next = stack->next;
	while (temp->next != stack)
	{
		if (temp->data > next->data)
			return (1);
		temp = temp->next;
		next = next->next;
	}
	return (0);
}

int		smallest_node(t_node *top)
{
	t_node *next;
	t_node *previous;

	next = top->next;
	previous = top->previous;
	if (top->data < next->data && top->data < previous->data)
		return (0);
	else if(next->data < top->data && next->data < previous->data)
		return (1);
	else
		return (-1);
}

int		find_best_spot(int ref, t_node *dest, int dest_size, int id)
{
	int i;

	i = top_down_greater_than(dest, dest_size, ref, id);
	if ((i == 0 || i == dest_size) && dest)
		i = bottom_up_smaller_than(dest, dest_size, ref, id);
	if ((i == 0 || i == dest_size) && dest)
		i = find_biggest(dest, dest_size, id);
	return (i);
}

void	sort_small(t_stack *stack)
{
	int move;

	if ((is_sorted(stack->a)))
	{
		while (stack->a_size > 3)
		{
			move = smallest_node(stack->a);
			if (move == 1 && (swap(&stack->a)))
				ft_printf("sa\n");
			else if (move == -1 && (reverse_rotate(&stack->a)))
				ft_printf("rra\n");
			move = find_best_spot(stack->a->data, stack->b, stack->b_size, DESENNDING);
			rotate_best_to_top(&stack->b, move, stack->b_size, 'a');
			push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
			ft_printf("pb\n");
			if (move && move == stack->b_size - 1)
			{
			ft_printf("rb\n");
			rotate(&stack->b);
			}
//-------------------------------------------------------------------------//
			ft_printf("\n-------------\n");
			print_stack(stack);
			ft_printf("\n-------------\n");
//-------------------------------------------------------------------------//
		}
		sort_three(&stack->a);
		if (stack->b)
			embty_b_stack(stack);
	}
	// ft_printf("\n\n");
}
