/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:55:31 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/14 00:10:48 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		ft_errno('e', "Could not allocate memmory\n");
	if (ac > 1)
	{
		get_arguments(stack, av);
		if (stack->a_size <= 10 && stack->a_size > 0)
			sort_small(stack);
		else if (stack->a_size > 0)
			sort_big(stack);
	}
	stack->flag ? print_stack(stack) : 0;
	return (0);
}
