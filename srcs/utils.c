/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:08:12 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 04:19:10 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*data_init(t_data *data)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->a.top = NULL;
	data->a.end = NULL;
	data->b.top = NULL;
	data->b.end = NULL;
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

void	free_data(t_data *data)
{
	free_stack(&data->a);
	free_stack(&data->b);
	free(data);
}
