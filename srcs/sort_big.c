/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 08:52:35 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/07 14:28:04 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	embty_a_stack(t_stack *stack)
{
	t_node *temp;

	temp = stack->a->next;
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
		temp->distance_to_top = 0;
		++j;
		if (j < size / 2)
			temp->distance_to_top = ++i;
		else if (j >= size / 2)
			temp->distance_to_top = i-- + 1;
		temp = temp->next;
	}
}

void	distance_in_stack_a(t_stack *stack)
{
	int		i;
	int		num;
	t_node	*temp;

	temp = stack->b;
	i = 0;
	while (i <= stack->b_size)
	{
		temp->distance_in_a = 0;
		temp->distance_in_a = find_best_spot(temp->data, stack->a, stack->a_size, ASCENDING);
		num = temp->distance_in_a > (stack->a_size / 2) ? stack->a_size - temp->distance_in_a
			: temp->distance_in_a;
		temp->price = num + temp->distance_to_top;
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
	sort_three(&stack->a);
	while(stack->b_size)
	{

		distance_to_top(stack->b, stack->b_size);
		distance_in_stack_a(stack);
		rotate_best_to_top(&stack->b, cheapest_node(stack->b), stack->b_size, 'b');
		// ft_printf("\n-------------\n");
		// print_stack(stack);
		// ft_printf("\n-------------\n");
		rotate_best_to_top(&stack->a, stack->b->distance_in_a, stack->a_size, 'a');
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
		ft_printf("pa\n");

	}
	reset = find_best_spot(-2147483648, stack->a, stack->a_size, ASCENDING);
	rotate_best_to_top(&stack->a, reset, stack->a_size, 'a');
}
