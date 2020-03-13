/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:26 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/14 00:10:57 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	validate_command(char *line, int flag)
{
	if (!(ft_strequ(line, "ra") || ft_strequ(line, "rb")
		|| ft_strequ(line, "sa") || ft_strequ(line, "sb")
		|| ft_strequ(line, "pa") || ft_strequ(line, "pb")
		|| ft_strequ(line, "rr") || ft_strequ(line, "ss")
		|| ft_strequ(line, "rra") || ft_strequ(line, "rrb")
		|| ft_strequ(line, "rrr")))
		ft_errno(flag, ft_strjoin(line, " is not a valid command\n"));
}

void	double_command(t_stack *stack, char *line)
{
	if (ft_strequ(line, "rrr"))
	{
		reverse_rotate(&stack->b);
		reverse_rotate(&stack->a);
	}
	else if (ft_strequ(line, "rr"))
	{
		rotate(&stack->b);
		rotate(&stack->a);
	}
	else if (ft_strequ(line, "ss"))
	{
		swap(&stack->b);
		swap(&stack->a);
	}
}

void	execute_commands(t_stack *stack, char *line)
{
	if (ft_strequ(line, "ra"))
		rotate(&stack->a);
	else if (ft_strequ(line, "rb"))
		rotate(&stack->b);
	else if (ft_strequ(line, "pa"))
		push(&stack->a, &stack->a_size, &stack->b, &stack->b_size);
	else if (ft_strequ(line, "pb"))
		push(&stack->b, &stack->b_size, &stack->a, &stack->a_size);
	else if (ft_strequ(line, "sa"))
		swap(&stack->a);
	else if (ft_strequ(line, "sb"))
		swap(&stack->b);
	else if (ft_strequ(line, "rrb"))
		reverse_rotate(&stack->b);
	else if (ft_strequ(line, "rra"))
		reverse_rotate(&stack->a);
	else
		double_command(stack, line);
}

int		main(int ac, char **av)
{
	t_stack *stack;
	char	*line;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		ft_errno('e', "Could not allocate memmory\n");
	if (ac > 1)
		get_arguments(stack, av);
	while (get_next_line(0, &line))
	{
		validate_command(line, stack->flag);
		execute_commands(stack, line);
		ft_strdel(&line);
		stack->flag ? print_stack(stack) : 0;
	}
	if (!is_sorted(stack->a) && !stack->b_size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
