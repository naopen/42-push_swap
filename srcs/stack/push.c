/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:38:27 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 03:42:40 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Push the top of stack B to stack A
void	push_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (stack_size(b) == 0)
		return ;
	node = b->top;
	b->top = b->top->next;
	if (b->top)
		b->top->prev = NULL;
	if (a->top)
		a->top->prev = node;
	node->next = a->top;
	node->prev = NULL;
	a->top = node;
}

// Push the top of stack A to stack B
void	push_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (stack_size(a) == 0)
		return ;
	node = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	if (b->top)
		b->top->prev = node;
	node->next = b->top;
	node->prev = NULL;
	b->top = node;
}
