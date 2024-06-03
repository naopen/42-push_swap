/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:43:22 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:19:34 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A down by one
void	rev_rotate_a(t_stack *a)
{
	t_node	*temp;

	if (stack_size(a) < 2 || a->top == NULL || a->end == NULL)
		return ;
	temp = a->end;
	a->end = a->end->prev;
	a->end->next = NULL;
	temp->next = a->top;
	a->top = temp;
	ft_putstr_fd("rra\n", 1);
}

// Rotate stack B down by one
void	rev_rotate_b(t_stack *b)
{
	t_node	*temp;

	if (stack_size(b) <= 1 || b->top == NULL || b->end == NULL)
		return ;
	temp = b->end;
	b->end = b->end->prev;
	b->end->next = NULL;
	temp->next = b->top;
	b->top = temp;
	ft_putstr_fd("rrb\n", 1);
}
// Rotate both stacks down by one
void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_a(a);
	rev_rotate_b(b);
	ft_putstr_fd("rrr\n", 1);
}
