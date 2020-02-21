/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:55:31 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 10:02:48 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	connect_stack(t_stack *stack)
{
	t_node *temp;

	temp = stack->a;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = stack->a;
	stack->a->previous = temp;
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

char	**split_numbers(char **s)
{
	char	**ret;
	char	*temp;
	char	*temp2;
	int		i;

	i = 0;
	temp = ft_strdup(s[i]);
	while (s[++i])
	{
		temp2 = ft_strjoin2(temp, " ", s[i]);
		free(temp);
		temp = temp2;
	}
	ret = ft_strsplit(temp, ' ');
	free(temp);
	return (ret);
}

int		main(int ac, char **av)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		errno();
	if (ac > 1)
	{
		stack->a = read_arguments(NULL, split_numbers(av));
	}
	connect_stack(stack);
	print_stack(stack);
	return (0);
}
