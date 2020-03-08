/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:26 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/08 09:33:30 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack;
	char	*line;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		ft_errno();
	if (ac > 1)
		get_arguments(stack, av);
	while(get_next_line(0, &line))
		ft_printf("%s", line);
	if (!is_sorted(stack->a) && !stack->b_size)
		ft_printf("OK\n");
	return (0);
}
