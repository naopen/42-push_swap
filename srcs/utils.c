/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:06:11 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 04:40:08 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	return (stack->size); // Return the size directly
}

int	stack_max(t_stack *stack)
{
	int		max;
	t_node	*node;

	max = INT_MIN;
	node = stack->top;
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
