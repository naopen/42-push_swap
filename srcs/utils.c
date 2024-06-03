/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:06:11 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:38:59 by nkannan          ###   ########.fr       */
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
	t_node	*temp;

	if (stack_size(stack) == 0)
		args_error();
	temp = stack->top;
	max = temp->value;
	while (temp)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int		min;
	t_node	*temp;

	if (stack_size(stack) == 0)
		args_error();
	temp = stack->top;
	min = temp->value;
	while (temp)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

bool	is_sorted(t_stack *a)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = a->top;
	while (i < stack_size(a) - 1)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
		i++;
	}
	return (true);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// 各要素の値と、その値がソート済み配列の何番目に位置するかを計算し、
// その情報をノードに格納する関数
// この情報を用いて、どの要素をスタックBに移動するかを決定する

// 配列を使わずに、スタックaの要素を直接比較して圧縮インデックスを計算する
void	compress_idx(t_stack *a)
{
	t_node	*temp;
	int		i;
	int		*sorted_arr;
	int		j;

	sorted_arr = (int *)malloc(sizeof(int) * (a->size));
	if (!sorted_arr)
		malloc_error();
	temp = a->top;
	i = 0;
	while (i < a->size)
	{
		sorted_arr[i] = temp->value;
		temp = temp->next;
		i++;
	}
	bubble_sort(sorted_arr, a->size);
	temp = a->top;
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (sorted_arr[j] != temp->value)
			j++;
		temp->compressed_value = j;
		temp = temp->next;
		i++;
	}
	free(sorted_arr);
}
