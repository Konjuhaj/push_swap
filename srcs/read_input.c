/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 09:20:54 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/09 17:10:38 by bkonjuha         ###   ########.fr       */
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
	while (s[++i])
	{
		if (!(node = (t_node *)malloc(sizeof(t_node))))
			ft_errno();
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
	temp2 = NULL;
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

int		check_for_flags(char **s, t_stack *stack)
{
	if (ft_strequ(s[1], "-v") || ft_strequ(s[1], "-l"))
		if (ft_strlen(s[1]) == 2)
			stack->visual = s[1][1];
	if (ft_strequ(s[2], "-c") && ft_strlen(s[2]) == 2)
		stack->color = s[2][1];
	return (!(stack->visual == 0));
}

void	get_arguments(t_stack *stack, char **str)
{
	char	**s;
	int		move;

	move = 0;
	stack->visual = 0;
	if ((check_for_flags(str, stack)))
		move++;
	are_numbers(str + move);
	s = split_numbers(str + move);
	stack->a = read_arguments(NULL, s);
	stack->b = NULL;
	connect_stack(stack);
	are_doubles(stack);
	ft_strstrdel(&s);
}
