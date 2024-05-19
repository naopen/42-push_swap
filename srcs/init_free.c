/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:08:12 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 09:31:40 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_sort_env	*data_init(void)
{
	t_sort_env	*new_data;

	new_data = (t_sort_env *)ft_calloc(1, sizeof(t_sort_env));
	if (!new_data)
		exit(1);
	new_data->a.sentinel = ft_calloc(1, sizeof(t_node));
	if (!new_data->a.sentinel)
		exit(1);
	new_data->a.sentinel->next = new_data->a.sentinel;
	new_data->a.sentinel->prev = new_data->a.sentinel;
	new_data->a.size = 0;
	new_data->b.sentinel = ft_calloc(1, sizeof(t_node));
	if (!new_data->b.sentinel)
		exit(1);
	new_data->b.sentinel->next = new_data->b.sentinel;
	new_data->b.sentinel->prev = new_data->b.sentinel;
	return (new_data);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->sentinel->next;
	while (node != stack->sentinel)
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
