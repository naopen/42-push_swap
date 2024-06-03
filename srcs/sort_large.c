/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:45:42 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 02:48:26 by nkannan          ###   ########.fr       */
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
		if (current->compressed_value >= min_val
			&& current->compressed_value <= pivot_val)
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

// スタックの中央値以上の値かどうかを判定する関数
static bool	is_value_above_mid(t_stack *stack, int value)
{
	t_node	*current;
	int		count;
	int		i;

	if (stack->top == NULL || stack->end == NULL)
		return (false);
	count = stack_size(stack);
	i = 0;
	current = stack->top;
	while (i < count / 2)
	{
		if (current->compressed_value == value)
			return (true);
		current = current->next;
		i++;
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
		compress_idx(b);
		if (b->top->compressed_value == stack_max(b))
			push_a(a, b); // 最大値はaへ移動
		else if (is_value_above_mid(b, stack_max(b)))
			rotate_b(b); // 上半分に最大値がある場合は回転
		else
		{
			rev_rotate_b(b); // それ以外は下半分に最大値があるので逆回転
			push_a(a, b);    // 逆回転後、最大値をaへ移動
		}
	}
}
