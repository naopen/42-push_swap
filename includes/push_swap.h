/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:59:58 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 03:42:10 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

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

// スタック操作関数
void	push_a(t_stack *a, t_stack *b); // スタックBのトップをスタックAにプッシュ
void	push_b(t_stack *a, t_stack *b); // スタックAのトップをスタックBにプッシュ

void	rotate_a(t_stack *a);           // スタックAを1つ上へローテート
void	rotate_b(t_stack *b);           // スタックBを1つ上へローテート
void	rotate_r(t_stack *a, t_stack *b); // スタックAとスタックBを1つ上へローテート

void	reverse_rotate_a(t_stack *a);   // スタックAを1つ下へローテート
void	reverse_rotate_b(t_stack *b);   // スタックBを1つ下へローテート
void	reverse_rotate_r(t_stack *a, t_stack *b); // スタックAとスタックBを1つ下へローテート

void	swap_a(t_stack *a);             // スタックAの上2つの要素を交換
void	swap_b(t_stack *b);             // スタックBの上2つの要素を交換
void	swap_s(t_stack *a, t_stack *b); // スタックAとスタックBの上2つの要素を交換

// ソート関連関数
void	radix_sort(t_stack *a, t_stack *b); // 基数ソート

// ユーティリティ関数
int	stack_size(t_stack *stack);  // スタックのサイズ（要素数）を計算
int	get_max_num(t_stack *stack); // スタック内の最大値を探す
int	get_min_num(t_stack *stack); // スタック内の最小値を探す

#endif
