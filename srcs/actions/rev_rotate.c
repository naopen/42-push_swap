/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:43:22 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/21 04:41:17 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A down by one
void	rev_rotate_a(t_stack *a)
{
	t_node	*node;

	if (stack_size(a) < 2)
		return ;
	node = a->end;
	a->end = a->end->prev;
	a->end->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	ft_putendl_fd("rra", 1);
}

// Rotate stack B down by one
void	rev_rotate_b(t_stack *b)
{
	t_node	*node;

	if (stack_size(b) < 2)
		return ;
	node = b->end;
	b->end = b->end->prev;
	b->end->next = NULL;
	node->prev = NULL;
	node->next = b->top;
	b->top->prev = node;
	b->top = node;
	ft_putendl_fd("rrb", 1);
}

// Rotate both stacks down by one
void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_a(a);
	rev_rotate_b(b);
}
