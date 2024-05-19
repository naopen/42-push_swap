/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:37:05 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:40:17 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Replace the top two elements of stack A
void	swap_a(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (stack_size(a) < 2)
		return ;
	first = a->sentinel->next;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = a->sentinel;
	first->prev = second;
	a->sentinel->next = second;
	ft_putendl_fd("sa", 1);
}

// Replace the top two elements of stack B
void	swap_b(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (stack_size(b) < 2)
		return ;
	first = b->sentinel->next;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = b->sentinel;
	first->prev = second;
	b->sentinel->next = second;
	ft_putendl_fd("sb", 1);
}

// Replace the top two elements of both stacks
void	swap_s(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}
