/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:59:58 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/16 05:33:52 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
	struct s_node *prev;
}		t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *end;
}		t_stack;

typedef struct s_data
{
	t_stack a;
	t_stack b;
}		t_data;

void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);

void	rev_rotate_a(t_stack *a);
void	rev_rotate_b(t_stack *b);
void	rev_rotate_r(t_stack *a, t_stack *b);

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_s(t_stack *a, t_stack *b);

void	radix_sort(t_stack *a, t_stack *b, int size);

void	stack_to_array(t_stack *stack, int *array);
void	array_to_stack(int *array, t_stack *stack, int size);
void	value_to_stack(t_stack *stack, int value);

int	stack_size(t_stack *stack);
int	stack_max(t_stack *stack);
int	stack_min(t_stack *stack);

void	args_error(void);
void	malloc_error(void);

t_data	*data_init(void);
void	free_stack(t_stack *stack);
void	free_data(t_data *data);

void	validate_args(int argc, char *argv[]);

#endif
