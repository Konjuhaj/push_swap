/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:25:48 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/28 10:11:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "../libraries/ft_printf/libft/libft.h"
# include "../libraries/ft_printf/includes/ft_printf.h"
# define ASCENDING 0
# define DESENNDING 1

typedef struct	s_node
{
	void		*next;
	int			data;
	int			distance_to_top;
	int			distance_in_a;
	int			price;
	void		*previous;
}				t_node;

typedef struct	s_stack
{
	t_node		*a;
	t_node		*b;
	int			a_size;
	int			b_size;
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

void			embty_b_stack(t_stack *stack);

void			rotate_best_to_top(t_node *node, int i, int size, char letter);


/*
**				Sorting Functions
*/

int				find_best_spot(int ref, t_node *b, int b_size, int id);

void			sort_small(t_stack *stack);

void			sort_three(t_node *node);

void			sort_big(t_stack *stack);

/*
**				Scanning functions
*/

int				top_down_greater_than(t_node *node, int size, int num, int id);

int				bottom_up_smaller_than(t_node *node, int size, int num, int id);

int				find_biggest(t_node *node, int size, int id);


/*
**				Checker Functions
*/

int				is_sorted(t_node *stack);


#endif
