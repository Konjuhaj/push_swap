/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:53:14 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 11:22:47 by bkonjuha         ###   ########.fr       */
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

void	calculate_prize(t_stack *stack)
{
	t_node *temp;

	temp = stack->a;
}

void	sort_small(t_stack *stack)
{
	if (is_sorted(stack))
		ft_printf("isn't sorted\n");
	ft_printf("SORTED\n");
}

// void	rotate(t_stack *stack)
// {

// }
