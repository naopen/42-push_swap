/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:39:25 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:16:10 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A up by one
void	rotate_a(t_stack *a)
{
	t_node	*temp;

	if (stack_size(a) <= 1 || a->top == NULL || a->end == NULL)
		return ;
	temp = a->top;
	a->top = a->top->next;
	a->end->next = temp;
	temp->next = NULL;
	a->end = temp;
	ft_putstr_fd("ra\n", 1);
}

// Rotate stack B up by one
void	rotate_b(t_stack *b)
{
	t_node	*temp;

	if (stack_size(b) <= 1 || b->top == NULL || b->end == NULL)
		return ;
	temp = b->top;
	b->top = b->top->next;
	b->end->next = temp;
	temp->next = NULL;
	b->end = temp;
	ft_putstr_fd("rb\n", 1);
}

// Rotate both stacks up by one
void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
	ft_putstr_fd("rr\n", 1);
}
