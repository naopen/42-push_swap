/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:06:11 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/21 06:09:06 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// stack構造体のメンバーsizeにアクセスするだけの関数
// 最初にスタックに入れる時及び、pushの度にsizeを更新しているため、
// その値を返すだけで現在のスタックのサイズを取得できる

int	stack_size(t_stack *stack)
{
	return (stack->size);
}

// まだソートされていないノードの数を返す
int	unsorted_count(t_stack *stack)
{
	int		count;
	t_node	*node;

	count = 0;
	node = stack->top;
	while (node)
	{
		if (node->is_sorted == 0)
			count++;
		node = node->next;
	}
	return (count);
}

int	stack_max(t_stack *stack)
{
	int		max;
	t_node	*node;

	max = INT_MIN;
	node = stack->top;
	if (node == NULL)
		exit(1);
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int		min;
	t_node	*node;

	min = INT_MAX;
	node = stack->top;
	if (node == NULL)
		exit(1);
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

int	compare_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	get_stack_value(t_stack *stack, int index)
{
	t_node	*node;
	int		i;

	if (index < 0 || index >= stack->size)
		return (INT_MIN);
	node = stack->top;
	i = 0;
	while (i < index)
	{
		node = node->next;
		i++;
	}
	return (node->value);
}

void	compress_coordinates(t_stack *a)
{
	t_node	*current;
	t_node	*compare;

	if (a == NULL || a->top == NULL)
		return ;
	current = a->top;
	while (current != NULL)
	{
		current->compressed_value = 0;
		compare = a->top;
		while (compare != NULL)
		{
			if (current->value >= compare->value)
				current->compressed_value++;
			compare = compare->next;
		}
		current = current->next;
	}
}
