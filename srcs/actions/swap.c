/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:37:05 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:20:39 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Replace the top two elements of stack A
void	swap_a(t_stack *a)
{
	t_node	*temp;

	if (stack_size(a) <= 1)
		return ;
	temp = a->top->next;
	a->top->next = temp->next;
	temp->next = a->top;
	a->top = temp;
	ft_putstr_fd("sa\n", 1);
}

// Replace the top two elements of stack B
void	swap_b(t_stack *b)
{
	t_node	*temp;

	if (stack_size(b) <= 1)
		return ;
	temp = b->top->next;
	b->top->next = temp->next;
	temp->next = b->top;
	b->top = temp;
	ft_putstr_fd("sb\n", 1);
}

// Replace the top two elements of both stacks
void	swap_s(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
	ft_putstr_fd("ss\n", 1);
}
