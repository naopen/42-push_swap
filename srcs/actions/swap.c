/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:37:05 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 08:26:59 by nkannan          ###   ########.fr       */
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
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	// 修正: first->nextがNULLでない場合のみ、second->nextのprevを更新する
	if (first->next)
		first->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	a->top = second;
	// 修正: スタックの要素数が2つの場合、末尾(a->end)を更新する
	if (stack_size(a) == 2)
		a->end = first;
	ft_putendl_fd("sa", 1);
}

// Replace the top two elements of stack B
void	swap_b(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (stack_size(b) < 2)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	b->top = second;
	if (stack_size(b) == 2)
		b->end = first;
	ft_putendl_fd("sb", 1);
}

// Replace the top two elements of both stacks
void	swap_s(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
	ft_putendl_fd("ss", 1);
}
