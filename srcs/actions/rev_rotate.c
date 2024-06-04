/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:43:22 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 08:22:05 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotate stack A down by one
void    rev_rotate_a(t_stack *a)
{
        t_node  *temp;

        if (a->top == NULL || a->end == NULL || stack_size(a) < 2)
                return ;
        temp = a->end;
        a->end = a->end->prev;
        if (a->end != NULL)
                a->end->next = NULL;
        temp->prev = NULL;
        temp->next = a->top;
        a->top->prev = temp;
        a->top = temp;
        ft_putendl_fd("rra", 1);
}

// Rotate stack B down by one
void	rev_rotate_b(t_stack *b)
{
	t_node	*temp;

	if (b->top == NULL || b->end == NULL || stack_size(b) < 2)
		return ;
	temp = b->end;
	b->end = b->end->prev;
	b->end->next = NULL;
	temp->prev = NULL;
	temp->next = b->top;
	b->top->prev = temp;
	b->top = temp;
	ft_putendl_fd("rrb", 1);
}

// Rotate both stacks down by one
void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_a(a);
	rev_rotate_b(b);
	ft_putendl_fd("rrr", 1);
}
