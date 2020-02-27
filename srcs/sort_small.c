/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:53:14 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/27 10:38:42 by bkonjuha         ###   ########.fr       */
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

void	find_best_spot(t_stack *stack)
{
	int i;

	i = top_down_greater_than(stack->b, stack->b_size, stack->a->data);
	if (i == 0 && stack->b)
		i = bottom_up_smaller_than(stack->b, stack->b_size, stack->a->data);
	if (i == 0 && stack->b)
		i = find_biggest(stack->b, stack->b_size);
	rotate_best_to_top(stack, i);
	push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
	ft_printf("pb\n");
	if (i && i == stack->b_size - 1)
	{
		ft_printf("rb\n");
		rotate(stack->b);
	}
}

void	sort_small(t_stack *stack)
{
	int movable_node;

	if ((is_sorted(stack->a)))
	{
		while (stack->a_size > 3)
		{
			movable_node = smallest_node(stack->a);
			if (movable_node == 1 && (swap(stack->a)))
				ft_printf("sa\n");
			else if (movable_node == -1 && (reverse_rotate(stack->a)))
				ft_printf("rra\n");
			find_best_spot(stack);
			ft_printf("\n-------------\n");
			print_stack(stack);
			ft_printf("\n-------------\n");
		}
		sort_three(stack->a);
		if (stack->b)
			empty_stack(stack);
	}
	// ft_printf("\n\n");
}
