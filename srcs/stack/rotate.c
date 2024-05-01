/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:39:25 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 13:22:38 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A up by one
void	rotate_a(t_stack *a)
{
	t_node	*node;

	if (a->top == NULL || a->end == NULL || stack_size(a) < 2)
		return ;
	if (a->top == a->end)
		return ;
	node = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	node->next = NULL;
	a->end->next = node;
	node->prev = a->end;
	a->end = node;
	ft_putendl_fd("ra", 1);
}

// Rotate stack B up by one
void	rotate_b(t_stack *b)
{
	t_node	*node;

	if (b->top == NULL || b->end == NULL || stack_size(b) < 2)
		return ;
	node = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;
	node->next = NULL;
	b->end->next = node;
	node->prev = b->end;
	b->end = node;
	ft_putendl_fd("rb", 1);
}

// Rotate both stacks up by one
void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}
