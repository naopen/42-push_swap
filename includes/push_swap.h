/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:59:58 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 04:10:57 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>

// スタックのノード構造体定義
typedef struct s_node
{
	int value;           // ノードが保持する数値
	struct s_node *next; // 次のノードへのポインタ
	struct s_node *prev; // 前のノードへのポインタ
}		t_node;

// スタック全体を管理する構造体定義
typedef struct s_stack
{
	t_node *top; // スタックの先頭ノードへのポインタ
	t_node *end; // スタックの最後尾ノードへのポインタ
}		t_stack;

typedef struct s_data
{
	t_stack a; // スタックA
	t_stack b; // スタックB
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
int	stack_size(t_stack *stack); // スタックのサイズ（要素数）を計算
int	stack_max(t_stack *stack);  // スタック内の最大値を探す
int	stack_min(t_stack *stack);  // スタック内の最小値を探す

#endif
