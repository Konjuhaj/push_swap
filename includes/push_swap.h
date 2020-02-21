/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:25:48 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 11:23:52 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "../libraries/ft_printf/libft/libft.h"
# include "../libraries/ft_printf/includes/ft_printf.h"


typedef struct s_node
{
	void *next;
	int data;
	int price;
	void *previous;
}				t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		a_size;
	int		b_size;
}				t_stack;

void			errno();

void			print_stack(t_stack *stack);

/*
**				Moving functions
*/


/*
**				Calculating Functions
*/

void			sort_small(t_stack *stack);


#endif
