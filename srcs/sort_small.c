/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:18:03 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/16 23:30:45 by nkannan          ###   ########.fr       */
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

	first = a->top->value;
	second = a->top->next->value;
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

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
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

// Get the index of the minimum value in the stack
static int	get_min_index(t_stack *stack)
{
	int		min_value;
	int		min_index;
	int		i;
	t_node	*temp;

	if (stack_size(stack) == 0)
		return (-1);
	temp = stack->top;
	min_value = temp->value;
	min_index = 0;
	i = 1;
	temp = temp->next;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}

// Sort four, five or six elements in stack a
// 1. Push smallest elements to b until 3 elements remain in a
// 2. Sort 3 elements in a
// 3. Push b to a

void	sort_four_to_six(t_stack *a, t_stack *b)
{
	int	min_index;

	while (stack_size(a) > 3)
	{
		min_index = get_min_index(a);
		if (min_index == 0)
			push_b(a, b);
		else if (min_index < stack_size(a) / 2)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
	sort_three(a);
	while (stack_size(b) > 0)
		push_a(a, b);
}
