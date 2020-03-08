/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 09:20:54 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/08 15:32:03 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	connect_stack(t_stack *stack)
{
	t_node *temp;

	temp = stack->a;
	stack->a_size = 0;
	stack->b_size = 0;
	while (++stack->a_size && temp && temp->next)
		temp = temp->next;
	temp->next = stack->a;
	stack->a->previous = temp;
}

t_node	*read_arguments(t_node *previous, char **s)
{
	int		i;
	long	temp;
	t_node	*node;

	i = 0;
	if (!(node = (t_node *)malloc(sizeof(t_node))))
		ft_errno();
	while (s[++i])
	{
		temp = ft_atol(s[i]);
		if (temp >= 2147483648 || temp <= -2147483649)
			ft_errno();
		node->data = temp;
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
		ft_strdel(&temp);
		temp = temp2;
	}
	ret = ft_strsplit(temp, ' ');
	ft_strdel(&temp);
	return (ret);
}

void	get_arguments(t_stack *stack, char **str)
{
	char	**s;

	are_numbers(str);
	s = split_numbers(str);
	stack->a = read_arguments(NULL, s);
	stack->b = NULL;
	connect_stack(stack);
	are_doubles(stack);
}
