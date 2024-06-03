/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:38:27 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 04:53:43 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Push the top of stack B to stack A
void	push_a(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (stack_size(b) == 0)
		return ;
	temp = b->top;
	b->top = b->top->next;
	if (b->top)
		b->top->prev = NULL;
	if (a->top)
		a->top->prev = temp;
	temp->next = a->top;
	temp->prev = NULL;
	a->top = temp;
	a->size++;
	b->size--;
	ft_putendl_fd("pa", 1);
}

// Push the top of stack A to stack B
void	push_b(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (stack_size(a) == 0)
		return ;
	temp = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	if (b->top)
		b->top->prev = temp;
	temp->next = b->top;
	temp->prev = NULL;
	b->top = temp;
	a->size--;
	b->size++;
	ft_putendl_fd("pb", 1);
}
