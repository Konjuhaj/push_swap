/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:55:31 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/08 10:53:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		ft_errno();
	if (ac > 1)
		get_arguments(stack, av);
	if (stack->a_size <= 10 && stack->a_size > 0)
		sort_small(stack);
	else if (stack->a_size > 0)
		sort_big(stack);
	// print_stack(stack);
	// system("leaks a.out | grep Process | tail -1");
	return (0);
}
