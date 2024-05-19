/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:43:22 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:39:37 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A down by one
void	rev_rotate_a(t_stack *a)
{
	t_node	*node;

	if (stack_size(a) < 2)
		return ;
	node = a->sentinel->prev;
	node->prev->next = a->sentinel;
	a->sentinel->prev = node->prev;
	node->next = a->sentinel->next;
	node->prev = a->sentinel;
	a->sentinel->next->prev = node;
	a->sentinel->next = node;
	ft_putendl_fd("rra", 1);
}

// Rotate stack B down by one
void	rev_rotate_b(t_stack *b)
{
	t_node	*node;

	if (stack_size(b) < 2)
		return ;
	node = b->sentinel->prev;
	node->prev->next = b->sentinel;
	b->sentinel->prev = node->prev;
	node->next = b->sentinel->next;
	node->prev = b->sentinel;
	b->sentinel->next->prev = node;
	b->sentinel->next = node;
	ft_putendl_fd("rrb", 1);
}

// Rotate both stacks down by one
void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_a(a);
	rev_rotate_b(b);
}
