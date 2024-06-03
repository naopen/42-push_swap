/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:38:27 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:13:11 by nkannan          ###   ########.fr       */
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
	if (stack_size(b) == 1)
		b->end = NULL;
	temp->next = a->top;
	a->top = temp;
	a->size++;
	b->size--;
	ft_putstr_fd("pa\n", 1);
}

// Push the top of stack A to stack B
void	push_b(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (stack_size(a) == 0)
		return ;
	temp = a->top;
	a->top = a->top->next;
	if (stack_size(a) == 1)
		a->end = NULL;
	temp->next = b->top;
	b->top = temp;
	b->size++;
	a->size--;
	ft_putstr_fd("pb\n", 1);
}
