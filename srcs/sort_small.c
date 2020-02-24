/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:53:14 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/24 11:00:18 by bkonjuha         ###   ########.fr       */
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

int		smallest_node(t_node *a)
{
	t_node *next;
	t_node *previous;

	next = a->next;
	previous = a->previous;
	if (a->data < next->data && a->data < previous->data)
		return (0);
	else if(next->data < a->data && next->data < previous->data)
		return (1);
	else
		return (-1);
}

void	sort_small(t_stack *stack)
{
	int movable_node;
	if (is_sorted(stack))
	{
		movable_node = smallest_node(stack->a);
		ft_printf("----------------\n");
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
		print_stack(stack);
		ft_printf("----------------\n");
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
		print_stack(stack);
		ft_printf("----------------\n");
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
		print_stack(stack);
		ft_printf("----------------\n");
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
		print_stack(stack);
		ft_printf("----------------\n");
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
		print_stack(stack);
		ft_printf("----------------\n");
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
		print_stack(stack);
	}
	ft_printf("SORTED\n");
}
