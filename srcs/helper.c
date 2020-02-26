/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:42:24 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/26 16:13:28 by bkonjuha         ###   ########.fr       */
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
	while (i && --i < stack->b_size / 2)
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
		if (temp->data < temp2->data)
			i++;
		else
			break ;
		temp = temp->next;
		temp2 = temp2->next;
	}
	rotate_best_to_top(stack, i + 1);
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
	find_biggest(stack);
	while (stack->b_size)
	{
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
		ft_printf("pa\n");
	}
}
