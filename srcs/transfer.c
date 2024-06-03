/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:43:05 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:06:16 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	value_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		malloc_error();
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->end;
	if (stack->end != NULL)
		stack->end->next = new_node;
	else
		stack->top = new_node;
	stack->end = new_node;
	stack->size++;
}
