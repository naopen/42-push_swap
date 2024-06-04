/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:39:25 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 17:56:23 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A up by one
void	rotate_a(t_stack *a)
{
	t_node	*temp;

	if (a->top == NULL || a->end == NULL || stack_size(a) <= 1)
		return ;
	temp = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	temp->next = NULL;
	a->end->next = temp;
	temp->prev = a->end;
	a->end = temp;
	ft_putendl_fd("ra", 1);
}

// Rotate stack B up by one
void	rotate_b(t_stack *b)
{
	t_node	*temp;

	if (b->top == NULL || b->end == NULL || stack_size(b) <= 1)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->top->prev = NULL;
	temp->next = NULL;
	b->end->next = temp;
	temp->prev = b->end;
	b->end = temp;
	ft_putendl_fd("rb", 1);
}

// Rotate both stacks up by one
void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
	ft_putendl_fd("rr", 1);
}
