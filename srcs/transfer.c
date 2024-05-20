/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:43:05 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/21 04:47:24 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_to_array(t_stack *stack, int *array)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current != NULL)
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
	stack->end = NULL;
	i = 0;
	while (i < size)
	{
		new_node = (t_node *)ft_calloc(1, sizeof(t_node));
		if (new_node == NULL)
			malloc_error();
		new_node->value = array[i];
		new_node->next = stack->top;
		new_node->prev = NULL;
		if (stack->top != NULL)
			stack->top->prev = new_node;
		stack->top = new_node;
		if (stack->end == NULL)
			stack->end = new_node;
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
	new_node->next = NULL;
	new_node->prev = stack->end;
	if (stack->end != NULL)
		stack->end->next = new_node;
	else
		stack->top = new_node;
	stack->end = new_node;
	stack->size++;
}
