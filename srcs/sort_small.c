/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:53:14 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/24 19:52:16 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_stack *stack)
{
	t_node *temp;
	t_node *next;

	temp = stack->a;
	next = stack->a->next;
	while (temp->next != stack->a)
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
	t_node *temp;
	int i;
	int compare;

	compare = stack->a->data;
	i = -1;
	temp = stack->b;
	while (++i < stack->b_size)
	{
		if (compare > temp->data)
			break ;
		temp = temp->next;
	}
	while (i && i > stack->b_size / 2 + 1 && i++ < stack->b_size)
	{
		rotate(stack->b);
		ft_printf("rb\n");
	}
	while (i && i-- < stack->b_size)
	{
		reverse_rotate(stack->b);
		ft_printf("rb\n");
	}
}

void	move_smallest_to_bottom(t_stack *stack)
{
	t_node *last;

	last = stack->b->previous;

	if (last->data > stack->b->data && stack->b_size > 1)
	{
		rotate(stack->b);
		ft_printf("rb\n");
	}
}

void	sort_small(t_stack *stack)
{
	int movable_node;
	t_node *temp;

	if (is_sorted(stack))
	{
		while (stack->a_size > 2)
		{
			movable_node = smallest_node(stack->a);
			if (movable_node == 1 && (swap(stack->a)))
				ft_printf("sa\n");
			else if (movable_node == -1 && (reverse_rotate(stack->a)))
				ft_printf("ra\n");
			find_best_spot(stack);
			push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
			move_smallest_to_bottom(stack);
			ft_printf("pb\n");
			// print_stack(stack);
		}
		temp = stack->a->next;
		if (temp->data < stack->a->data && (swap(stack->a)))
			ft_printf("sa\n");
		empty_stack(stack);
	}
}
