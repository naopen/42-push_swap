/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:18:03 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 17:11:42 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	countingSortForRadix(int *array, int size, int place)
{
	int	*output;
	int	count[10];
	int	i;
	int	index;

	output = malloc(sizeof(int) * size);
	if (!output)
		return ;
	i = 0;
	while (i < 10)
	{
		count[i] = 0;
		i++;
	}
	i = 0;
	while (i < size)
	{
		index = (array[i] / place) % 10;
		count[index]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		index = (array[i] / place) % 10;
		output[count[index] - 1] = array[i];
		count[index]--;
		i--;
	}
	i = 0;
	while (i < size)
	{
		array[i] = output[i];
		i++;
	}
	free(output);
}

void	radix_sort(t_stack *stack, int size)
{
	int	maxVal;
	int	*array;
	int	place;

	array = malloc(size * sizeof(int));
	if (!array)
		return ;
	stack_to_array(stack, array);
	maxVal = stack_max(stack);
	place = 1;
	while (maxVal / place > 0)
	{
		countingSortForRadix(array, size, place);
		place *= 10;
	}
	array_to_stack(array, stack, size);
	free(array);
}
