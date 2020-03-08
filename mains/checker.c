/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:26 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/08 10:33:48 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	validate_command(char *line)
{
	if (!(ft_strequ(line, "ra") || ft_strequ(line, "rb")
		|| ft_strequ(line, "sa") || ft_strequ(line, "sb")
		|| ft_strequ(line, "pa") || ft_strequ(line, "pb")
		|| ft_strequ(line, "rr") || ft_strequ(line, "ss")
		|| ft_strequ(line, "rra") || ft_strequ(line, "rrb")
		|| ft_strequ(line, "rrr")))
		ft_errno();
}

void	execute_commands(t_stack *stack, char *line)
{
	if (ft_strequ(line, "ra") && stack->a_size)
		rotate(&stack->a);
	else if (ft_strequ(line, "rb") && stack->b_size)
		rotate(&stack->b);
	else if (ft_strequ(line, "pa") && stack->b_size)
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
	else if (ft_strequ(line, "pb") && stack->a_size)
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
	else if (ft_strequ(line, "sa") && stack->a_size)
		swap(&stack->a);
	else if (ft_strequ(line, "sb") && stack->b_size)
		swap(&stack->b);
	else if (ft_strequ(line, "rrb") && stack->b_size)
		reverse_rotate(&stack->b);
	else if (ft_strequ(line, "rra") && stack->a_size)
		reverse_rotate(&stack->a);
	else if (ft_strequ(line, "rrr") && stack->b_size && stack->a_size)
	{
		reverse_rotate(&stack->b);
		reverse_rotate(&stack->a);
	}
	else if (ft_strequ(line, "rr") && stack->b_size && stack->a_size)
	{
		rotate(&stack->b);
		rotate(&stack->a);
	}
	else if (ft_strequ(line, "ss") && stack->b_size && stack->a_size)
	{
		swap(&stack->b);
		swap(&stack->a);
	}
}

int		main(int ac, char **av)
{
	t_stack *stack;
	char	*line;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		ft_errno();
	if (ac > 1)
		get_arguments(stack, av);
	while(get_next_line(0, &line))
	{
		validate_command(line);
		execute_commands(stack, line);
		ft_strdel(&line);
	}
	if (!is_sorted(stack->a) && !stack->b_size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
