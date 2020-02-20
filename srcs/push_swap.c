/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:55:31 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/20 15:37:07 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	connect_stack(t_node *a)
{
	t_node *temp;

	temp = a;
	while (temp && temp->next)
		temp->next = temp;
	temp->next = a;
	a->previous = temp;
}

t_node	*read_arguments(t_node *previous, char **s)
{
	int i;
	t_node *node;

	i = 0;
	if (!(node = (t_node *)malloc(sizeof(t_node))))
		errno();
	while (s[++i])
	{
		node->data = ft_atoi(s[i]);
		node->next = read_arguments(node, (s + i));
		node->previous = previous;
		return (node);
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		errno();
	if (ac > 1)
		stack->a = read_arguments(NULL, av);
	print_stack(stack);
	return (0);
}
