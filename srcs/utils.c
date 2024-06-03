/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:06:11 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:06:41 by nkannan          ###   ########.fr       */
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

// 各要素の値と、その値がソート済み配列の何番目に位置するかを計算し、
// その情報をノードに格納する関数
// この情報を用いて、どの要素をスタックBに移動するかを決定する

// 配列を使わずに、スタックaの要素を直接比較して圧縮インデックスを計算する
void	compress_idx(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		compressed_value;

	current = a->top;
	while (current != NULL)
	{
		compare = a->top;
		compressed_value = 0;
		while (compare != NULL)
		{
			if (current->value > compare->value)
				compressed_value++;
			compare = compare->next;
		}
		current->compressed_value = compressed_value;
		current = current->next;
	}
}
