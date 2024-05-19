/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:18:03 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:46:00 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Sort two elements in stack a
// 1. If first > second, swap top two elements
// 2. If first < second, nothing to do

void	sort_two(t_stack *a)
{
	int	first;
	int	second;

	if (stack_size(a) != 2)
		return ;
	first = a->sentinel->next->value;
	second = a->sentinel->next->next->value;
	if (first > second)
		swap_a(a);
}

// Sort three elements in stack a
// 1. If first > second > third, swap top two elements and reverse rotate
// 2. If first > third > second, rotate
// 3. If second > first > third, reverse rotate
// 4. If second > third > first, swap top two elements and rotate
// 5. If third > first > second, swap top two elements
// 6. If third > second > first, nothing to do

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(a) != 3)
		return ;
	first = a->sentinel->next->value;
	second = a->sentinel->next->next->value;
	third = a->sentinel->next->next->next->value;
	if (first > second && second > third)
	{
		swap_a(a);
		rev_rotate_a(a);
	}
	else if (first > third && third > second)
		rotate_a(a);
	else if (second > first && first > third)
		rev_rotate_a(a);
	else if (second > third && third > first)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (third > first && first > second)
		swap_a(a);
}

// Sort four, five or six elements in stack a
// 1. Push a to b until a has 3 elements
// 2. Sort 3 elements in a
// 3. Push b to a

void	sort_four_to_six(t_stack *a, t_stack *b)
{
	int	size;
	int	push_count;

	size = stack_size(a);
	push_count = size - 3;
	while (push_count--)
		push_b(a, b);
	sort_three(a);
	while (size--)
		push_a(a, b);
}
