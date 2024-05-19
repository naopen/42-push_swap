/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:38:27 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:36:53 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Push the top of stack B to stack A
void	push_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (stack_size(b) == 0)
		return ;
	node = b->sentinel->next;
	b->sentinel->next = node->next;
	node->next->prev = b->sentinel;
	node->next = a->sentinel->next;
	node->prev = a->sentinel;
	a->sentinel->next->prev = node;
	a->sentinel->next = node;
	a->size++;
	b->size--;
	ft_putendl_fd("pa", 1);
}

// Push the top of stack A to stack B
void	push_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (stack_size(a) == 0)
		return ;
	node = a->sentinel->next;
	a->sentinel->next = node->next;
	node->next->prev = a->sentinel;
	node->next = b->sentinel->next;
	node->prev = b->sentinel;
	b->sentinel->next->prev = node;
	b->sentinel->next = node;
	b->size++;
	a->size--;
	ft_putendl_fd("pb", 1);
}
