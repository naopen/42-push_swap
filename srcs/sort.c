/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:47:02 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 03:52:47 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_by_digit(t_stack *a, t_stack *b, int digit)
{
	int		i;
	int		size;
	int		bit;

	i = 0;
	size = stack_size(a);
	bit = 1 << digit;
	while (i < size)
	{
		if ((a->top->value & bit) == 0)
			push_b(a, b);
		else
			rotate_a(a);
		i++;
	}
	while (stack_size(b) > 0)
		push_a(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		i;
	int		max;
	int		digit;

	i = 0;
	max = stack_max(a);
	digit = ft_numlen(max);
	while (i < digit)
	{
		sort_by_digit(a, b, i);
		i++;
	}
}
