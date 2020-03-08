/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:37:40 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/08 13:29:46 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		are_doubles(t_stack *stack)
{
	t_node	*curr;
	t_node	*comp;
	int		i;

	curr = stack->a;
	comp = stack->a->next;
	i = -1;
	while (++i < stack->a_size)
	{
		while (comp != curr)
		{
			if (curr->data == comp->data)
				ft_errno();
			comp = comp->next;
		}
		curr = curr->next;
		comp = curr->next;
	}
	return (1);
}

int		are_numbers(char **s)
{
	int i;
	int j;
	int fine;

	j = 0;
	while(s[++j])
	{
		fine = 1;
		i = -1;
		while(s[j][++i])
		{
			s[j][i] != ' ' ? fine = ft_isdigit(s[j][i]) : 0;
			if (s[j][i] == '-' || s[j][i] == '+')
				fine = ft_isdigit(s[j][i + 1]);
			if (fine == 0)
				ft_errno();
		}
	}
	return (0);
}
