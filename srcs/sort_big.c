/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:52:35 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/28 10:13:10 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	embty_a_stack(t_stack *stack)
{
	while(stack->a_size > 3)
	{
		ft_printf("pb\n");
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
	}
}

void	distance_to_top(t_node *node, int size)
{
	t_node	*temp;
	int		i;
	int		j;

	temp = node->next;
	i = 0;
	j = 0;
	node->distance_to_top = 0;
	while (temp != node)
	{
		++j;
		if (j < size / 2)
			temp->distance_to_top = ++i;
		else if (j > size / 2)
			temp->distance_to_top = --i;
		temp = temp->next;
	}
}

void	distance_in_stack_a(t_stack *stack)
{
	int i;
	t_node *temp;

	temp = stack->b;
	i = 0;
	while (i <= stack->b_size)
	{
		temp->distance_in_a = find_best_spot(stack->b->data, stack->a, stack->a_size, ASCENDING);
		temp->price = temp->distance_in_a + temp->distance_to_top;
		temp = temp->next;
		i++;
	}
}

int	cheapest_node(t_node *node)
{
	t_node	*temp;
	int		base;
	int		location;
	int		i;

	temp = node->next;
	base = node->price;
	location = 0;
	i = 0;
	while (temp != node)
	{
		++i;
		if (base > temp->price)
		{
			location = i;
			base = temp->price;
		}
		temp = temp->next;
	}
	return (location);
}

void	sort_big(t_stack *stack)
{
	int reset;
	embty_a_stack(stack);
	sort_three(stack->a);
	while(stack->b_size)
	{
		ft_printf("\n-------------\n");
		print_stack(stack);
		ft_printf("\n-------------\n");
		distance_to_top(stack->b, stack->b_size);
		distance_in_stack_a(stack);
		rotate_best_to_top(stack->b, cheapest_node(stack->b), stack->b_size, 'b');
		rotate_best_to_top(stack->a, stack->b->distance_in_a, stack->a_size, 'a');
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
		ft_printf("pa\n");

	}
	reset = find_best_spot(-2147483648, stack->a, stack->a_size, ASCENDING);
	rotate_best_to_top(stack->a, reset, stack->a_size, 'a');
}
