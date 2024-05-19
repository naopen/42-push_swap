/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:39:25 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:39:49 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A up by one
void	rotate_a(t_stack *a)
{
	t_node	*node;

	if (stack_size(a) < 2)
		return ;
	node = a->sentinel->next;
	a->sentinel->next = node->next;
	node->next->prev = a->sentinel;
	node->next = a->sentinel;
	node->prev = a->sentinel->prev;
	a->sentinel->prev->next = node;
	a->sentinel->prev = node;
	ft_putendl_fd("ra", 1);
}

// Rotate stack B up by one
void	rotate_b(t_stack *b)
{
	t_node	*node;

	if (stack_size(b) < 2)
		return ;
	node = b->sentinel->next;
	b->sentinel->next = node->next;
	node->next->prev = b->sentinel;
	node->next = b->sentinel;
	node->prev = b->sentinel->prev;
	b->sentinel->prev->next = node;
	b->sentinel->prev = node;
	ft_putendl_fd("rb", 1);
}

// Rotate both stacks up by one
void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}
