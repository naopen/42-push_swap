/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:45:42 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 02:36:12 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_to_stack_b(t_stack *a, t_stack *b, int min_val, int pivot_val)
{
	int		index;
	int		median;
	t_node	*current;

	index = 0;
	median = (pivot_val + min_val) / 2;
	while (index < stack_size(a))
	{
		current = a->top;
		if (current->compressed_value <= pivot_val)
		{
			push_b(a, b);
			if (current->compressed_value <= median)
				rotate_b(b);
		}
		else
			rotate_a(a);
		index++;
	}
}

static void	move_all_to_stack_b(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < stack_size(a))
	{
		push_b(a, b);
		i++;
	}
}

static bool	is_value_above_mid(t_stack *stack, int value)
{
	t_node	*current;
	t_node	*last;

	if (stack->top == NULL || stack->end == NULL) // スタックが空の場合はfalseを返す
		return (false);

	current = stack->top;
	last = stack->end;
	// lastがNULLになることはないので、last->next != NULLのチェックは不要
	while (current != NULL && last != NULL) // currentとlastがNULLでないことを確認
	{
		if (current->compressed_value == value)
			return (true);
		if (last->compressed_value == value)
			return (false);
		current = current->next;
		last = last->prev;
		// currentとlastが交差したら終了
		if (current == last || current->next == last)
			break;
	}
	return (false);
}


void	sort_large(t_stack *a, t_stack *b)
{
	int	pivot;
	int	min_val;
	int	index;

	index = 1;
	pivot = -1;
	while (index < DIVISION)
	{
		min_val = pivot + 1;
		pivot = stack_max(a) / DIVISION * index;
		move_to_stack_b(a, b, min_val, pivot);
		index++;
	}
	move_all_to_stack_b(a, b);
	while (stack_size(b) > 0)
	{
		if (b->top->compressed_value == stack_max(b))
			push_a(a, b);
		else if (is_value_above_mid(b, stack_max(b)))
			rotate_b(b);
		else
			rev_rotate_b(b);
	}
}
