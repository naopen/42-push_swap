/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:59:58 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 12:53:01 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int value;
	struct s_node *next;
	struct s_node *prev;
}		t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *end;
}		t_stack;

typedef struct s_data
{
	t_stack a;
	t_stack b;
}		t_data;

// スタック操作関数
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);

void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_r(t_stack *a, t_stack *b);

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_s(t_stack *a, t_stack *b);

// ソート関連関数
void	radix_sort(t_stack *a, t_stack *b); // 基数ソート

// ユーティリティ関数
void	add_value_to_stack(t_stack *stack, int value); // スタックに値を追加
int	stack_size(t_stack *stack); // スタックのサイズ（要素数）を計算
int	stack_max(t_stack *stack);  // スタック内の最大値を探す
int	stack_min(t_stack *stack);  // スタック内の最小値を探す

// エラー関連関数
void	args_error(void);  // 引数エラー
void	malloc_error(void); // メモリ確保エラー

// メモリ解放関数
t_data	*data_init(void);
void	free_stack(t_stack *stack); // スタックのメモリを解放
void	free_data(t_data *data);    // データ構造体のメモリを解放


#endif
