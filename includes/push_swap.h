/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:25:48 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/27 10:35:20 by bkonjuha         ###   ########.fr       */
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

int				rotate(t_node *top_node);

int				reverse_rotate(t_node *top_node);

int				swap(t_node *top_node);

int				push(t_node **dest, int *dest_size, t_node **src, int *src_size);

/*
**				Helper Functions
*/

void			empty_stack(t_stack *stack);

void			rotate_best_to_top(t_stack *stack, int i);


/*
**				Sorting Functions
*/

void			find_best_spot(t_stack *stack);

void			sort_small(t_stack *stack);

void			sort_three(t_node *node);

/*
**				Scanning functions
*/

int				top_down_greater_than(t_node *node, int size, int num);

int				bottom_up_smaller_than(t_node *node, int size, int num);

int				find_biggest(t_node *node, int size);


/*
**				Checker Functions
*/

int				is_sorted(t_node *stack);


#endif
