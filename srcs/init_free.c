/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:08:12 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 08:00:28 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_sort_env	*data_init(void)
{
	t_sort_env	*data;

	data = (t_sort_env *)malloc(sizeof(t_sort_env));
	if (!data)
		malloc_error();
	printf("Address1: %p\n", (void*)data);
	data->a.top = NULL;
	data->a.end = NULL;
	data->a.size = 0;
	data->b.top = NULL;
	data->b.end = NULL;
	data->b.size = 0;
	return (data);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	free_data(t_sort_env *data)
{
	free_stack(&data->a);
	free_stack(&data->b);
	free(data);
}

void	free_node(t_stack *stack)
{
	t_node	*node;
	while (stack->top)
	{
		node = stack->top;
		stack->top = stack->top->next;
		printf("Address4: %p\n", (void*)node);
		free(node);
		node = NULL;
	}
}
