/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:59:58 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 05:52:55 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// sort_env has a and b stacks
// stack has top and end nodes
// node has next and prev nodes

typedef struct s_node
{
	int				value;
	int				compressed_value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*end;
	int				size;
}					t_stack;

typedef struct s_sort_env
{
	t_stack			a;
	t_stack			b;
}					t_sort_env;

void				push_a(t_stack *a, t_stack *b);
void				push_b(t_stack *a, t_stack *b);

void				rotate_a(t_stack *a);
void				rotate_b(t_stack *b);
void				rotate_r(t_stack *a, t_stack *b);

void				rev_rotate_a(t_stack *a);
void				rev_rotate_b(t_stack *b);
void				rev_rotate_r(t_stack *a, t_stack *b);

void				swap_a(t_stack *a);
void				swap_b(t_stack *b);
void				swap_s(t_stack *a, t_stack *b);

void				validate_args(int argc, char *argv[]);

void				args_error(void);
void				malloc_error(void);

t_sort_env			*data_init(void);
void				free_stack(t_stack *stack);
void				free_data(t_sort_env *data);

void				compress_idx(t_stack *a);

void				sort(t_stack *a, t_stack *b);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				sort_four_to_six(t_stack *a, t_stack *b);
void				sort_large(t_stack *a, t_stack *b);

int					stack_size(t_stack *stack);
int					stack_max(t_stack *stack);
int					stack_min(t_stack *stack);
bool				is_stack_sorted(t_stack *a);
void				value_to_stack(t_stack *stack, int value);

#endif
