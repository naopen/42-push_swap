/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:06:11 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 07:44:47 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

bool	is_stack_sorted(t_stack *a)
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

void	value_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		malloc_error();
	printf("Address2: %p\n", (void*)new_node);
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
		stack->end = new_node;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = stack->end;
		stack->end->next = new_node;
		stack->end = new_node;
	}
	stack->size++;
}
