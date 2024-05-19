/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:43:05 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:35:21 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_to_array(t_stack *stack, int *array)
{
	t_node	*current;
	int		i;

	current = stack->sentinel->next;
	i = 0;
	while (current != stack->sentinel)
	{
		array[i] = current->value;
		i++;
		current = current->next;
	}
}

void	array_to_stack(int *array, t_stack *stack, int size)
{
	t_node	*new_node;
	int		i;

	free_stack(stack);
	i = 0;
	while (i < size)
	{
		new_node = (t_node *)ft_calloc(1, sizeof(t_node));
		if (new_node == NULL)
			malloc_error();
		new_node->value = array[i];
		new_node->next = stack->sentinel;
		new_node->prev = stack->sentinel->prev;
		stack->sentinel->prev->next = new_node;
		stack->sentinel->prev = new_node;
		stack->size++;
		i++;
	}
}

void	value_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		malloc_error();
	new_node->value = value;
	new_node->next = stack->sentinel;
	new_node->prev = stack->sentinel->prev;
	stack->sentinel->prev->next = new_node;
	stack->sentinel->prev = new_node;
	stack->size++;
}
