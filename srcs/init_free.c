/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:08:12 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 01:45:15 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_sort_env	*data_init(void)
{
	t_sort_env	*new_data;

	new_data = (t_sort_env *)malloc(sizeof(t_sort_env));
	if (!new_data)
		exit(1);
	new_data->a.top = NULL;
	new_data->a.end = NULL;
	new_data->b.top = NULL;
	new_data->b.end = NULL;
	return (new_data);
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
