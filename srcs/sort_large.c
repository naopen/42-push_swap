/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:45:42 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/20 00:49:53 by nkannan          ###   ########.fr       */
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
void	compress_idx(t_stack *a)
{
	int		*array;
	int		size;
	t_node	*node;
	int		i;

	size = a->size;
	array = (int *)calloc(size, sizeof(int));
	stack_to_array(a, array);
	quick_sort_array(array, 0, size - 1);
	node = a->sentinel->next;
	while (node != a->sentinel)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == node->value)
			{
				node->index = i;
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
	if (index <= stack->size / 2)
	{
		while (index-- > 0)
			rotate_a(stack);
	}
	else
	{
		index = stack->size - index;
		while (index-- > 0)
			rev_rotate_a(stack);
	}
}

// 選択の最適化
void	optimized_push(t_stack *a, t_stack *b, int *indices, int count)
{
	int	temp_count;

	temp_count = count;
	while (count > 0)
		optimized_rotate(a, indices[--count]);
	while (temp_count-- > 0)
		push_b(a, b);
}

int	partition_stack(t_sort_env *data, int *indices, int low, int high)
{
    int pivot;
    int i;
    int j;
    int temp;

    pivot = get_stack_value(&data->a, high); // 高い位置にある要素をピボットとして選択
    i = low - 1; // iは低いインデックスの一つ前から開始
    j = low; // jは低いインデックスから開始
    while (j <= high - 1) // 高いインデックスの一つ前までループ
    {
        if (get_stack_value(&data->a, j) < pivot) // もし現在の要素がピボットより小さいならば
        {
            i++; // iをインクリメント
            // indicesのiとjの位置にある要素を交換
            temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;

            // rotate_a(&data->a); この行を削除
        }
        j++; // jをインクリメント
    }
    // パーティションの最後でi+1と高いインデックスの要素を交換
    temp = indices[i + 1];
    indices[i + 1] = indices[high];
    indices[high] = temp;

    optimized_push(&data->a, &data->b, indices, i + 1); // 最適化されたプッシュ操作を実行
    return (i + 1); // 新しいパーティションのインデックスを返す
}


// スタックAの中央値を計算し、その値より小さい値をBに移動
// スタックAのTOPの値を中央値と比較し、中央値より小さい場合はBに移動
// それ以外の場合はAを回転させ、次の値を比較
// is_sortedフラグの立っている値は、対象外

void	push_half_to_b(t_stack *a, t_stack *b)
{
	int	median;
	int	count;
	int	total_elements;
	int	checked_elements;

	median = (stack_max(a) + stack_min(a)) / 2;
	count = 0;
	total_elements = stack_size(a);
	checked_elements = 0;

	while (count < total_elements / 2 && checked_elements < total_elements)
	{
		if (a->sentinel->next->is_sorted == false)
		{
			if (get_stack_value(a, 0) < median)
			{
				push_b(a, b);
				count++;
			}
			else
				rotate_a(a);
		}
		else
			rotate_a(a);
		checked_elements++;
	}
}


// スタックBをクイックソート
void	quick_sort_b(t_stack *b)
{
	int	*array;
	int	size;

	size = stack_size(b);
	array = (int *)calloc(size, sizeof(int));
	stack_to_array(b, array);
	quick_sort_array(array, 0, size - 1);
	array_to_stack(array, b, size);
	free(array);
}

// ソート済みのスタックBをis_sortedフラグを立ててスタックAに移動
void	push_sorted_to_a(t_stack *a, t_stack *b)
{
	while (stack_size(b) > 0)
	{
		push_a(a, b);
		a->sentinel->next->is_sorted = true;
	}
}

// スタックがソートされているかを確認する関数
bool is_sorted(t_stack *stack)
{
    t_node *current = stack->sentinel->next;
    while (current->next != stack->sentinel)
    {
        if (current->value > current->next->value)
            return false;
        current = current->next;
    }
    return true;
}

// ステップ1: Aを半分に分割
// Aの半分はそのまま残し、もう半分をBに移動
// ステップ2: Bを繰り返し半分に分割
// 分割するたびに、適切な処理(例: ソートや値の確定)を行う
// ステップ3: Aの半分をBに移動し、再びBを分割
// このステップは、AとB間で要素が移動し、Bがさらに細分化される
// ステップ4: Bを再度分割
// ステップ5: Aの末尾にソート済みの値を確定
// このステップでは、Aに対してソートや値の確定を行う処理を実施

void	sort_large(t_stack *a, t_stack *b)
{
	if (stack_size(a) <= 6)
		return (sort_four_to_six(a, b));

	while (unsorted_count(a) > 0)
	{
		compress_idx(a);
		push_half_to_b(a, b);
        while (stack_size(b) > SORT_SIZE)
        {
            quick_sort_b(b);
            // スタックbがソートされたか確認する
            if (is_sorted(b))
                break;
        }
		push_sorted_to_a(a, b);
	}
}
