/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:25:48 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/21 12:20:21 by bkonjuha         ###   ########.fr       */
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

void			rotate(t_node *top_node);

void			reverse_rotate(t_node *top_node);

void			swap(t_node *top_node);

void			push(t_node *dest, t_node *src);


/*
**				Calculating Functions
*/

void			sort_small(t_stack *stack);


#endif
