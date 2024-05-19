/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:45:42 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:45:00 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// push_swapの流れ：7個以上のとき
// aの末尾へ小さい順に数字を挿入し、ソート済み扱いにしていく
// 初期状態は、aに数値がある
// aの数値を大小で分け、bにpushする
// bが分割できなくなるまで、bの数値を大小で分け、aにpushする
// 残ったbの数値を小さい順にaの末尾へ移動する
// aをbへpushし、bの分割を繰り返す

// 配列のパーティションを行う関数
static int	partition_array(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

// 配列をクイックソートする関数
static void	quick_sort_array(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition_array(arr, low, high);
		quick_sort_array(arr, low, pi - 1);
		quick_sort_array(arr, pi + 1, high);
	}
}

// 座標圧縮を行う関数
void	compress_coordinates(t_stack *a)
{
	int		*array;
	int		size;
	t_node	*node;
	int		i;

	size = stack_size(a);
	array = (int *)malloc(sizeof(int) * size);
	stack_to_array(a, array);
	quick_sort_array(array, 0, size - 1);
	node = a->sentinel->next;
	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == node->value)
			{
				node->value = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
	free(array);
}

// 回転操作の最適化
void	optimized_rotate(t_stack *stack, int index)
{
	if (index <= stack_size(stack) / 2)
		while (index-- > 0)
			rotate_a(stack);
	else
	{
		index = stack_size(stack) - index;
		while (index-- > 0)
			rev_rotate_a(stack);
	}
}

// 選択の最適化
void	optimized_push(t_stack *a, t_stack *b, int *indices, int count)
{
	while (count-- > 0)
		optimized_rotate(a, indices[count]);
	while (count-- > 0)
		push_b(a, b);
}

static void	partition_stack(t_sort_env *data, int *indices, int size, int median)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (data->a.sentinel->next->value < median)
			indices[count++] = i;
		rotate_a(&data->a);
		i++;
	}
	optimized_push(&data->a, &data->b, indices, count);
	while (stack_size(&data->b) > 0)
		push_a(&data->a, &data->b);
}

void	sort_large(t_sort_env *data)
{
	int		median;
	int		size;
	int		*indices;

	compress_coordinates(&data->a);
	size = stack_size(&data->a);
	indices = (int *)malloc(sizeof(int) * size);
	while (size > 3)
	{
		median = (stack_min(&data->a) + stack_max(&data->a)) / 2;
		partition_stack(data, indices, size, median);
		size = stack_size(&data->a);
	}
	sort_three(&data->a);
	while (stack_size(&data->b) > 0)
		push_a(&data->a, &data->b);
	free(indices);
}
