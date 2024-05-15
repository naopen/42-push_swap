/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:18:03 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/16 05:34:06 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		swap_a(a);
	if (a->top->next->value > a->end->value)
	{
		rev_rotate_a(a);
		if (a->top->value > a->top->next->value)
			swap_a(a);
	}
}

static void	sort_small(t_stack *a, t_stack *b)
{
	while (stack_size(a) > 3)
		push_b(a, b);
	sort_three(a);
	while (stack_size(b) > 0)
		push_a(a, b);
}

void	radix_sort(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	j;
	int	max_bits;
	int	max_num;

	max_num = stack_max(a);
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->value >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while (stack_size(b) > 0)
			push_a(a, b);
		i++;
	}
}

void	sort(t_data *data)
{
	if (stack_size(&data->a) <= 3)
		sort_three(&data->a);
	else if (stack_size(&data->a) <= 6)
		sort_small(&data->a, &data->b);
	else
		radix_sort(&data->a, &data->b, stack_size(&data->a));
}
