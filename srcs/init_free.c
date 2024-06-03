/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:08:12 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:26:56 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_sort_env	*data_init(void)
{
	t_sort_env	*data;

	data = (t_sort_env *)malloc(sizeof(t_sort_env));
	if (!data)
		malloc_error();
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
	t_node	*temp;

	while (stack->size)
	{
		temp = stack->top->next;
		free(stack->top);
		stack->top = temp;
		stack->size--;
	}
}

void	free_data(t_sort_env *data)
{
	free_stack(&data->a);
	free_stack(&data->b);
	free(data);
}
