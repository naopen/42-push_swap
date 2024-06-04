/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:45:42 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 07:45:19 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// Copy the values of stack a to the sorted array

static void	copy_stack_to_array(t_stack *a, int *sorted_arr)
{
	t_node	*temp;
	int		i;

	temp = a->top;
	i = 0;
	while (i < a->size)
	{
		sorted_arr[i] = temp->value;
		temp = temp->next;
		i++;
	}
}

// Set the compressed index for each node using the sorted array

static void	set_compressed_idx(t_stack *a, int *sorted_arr)
{
	t_node	*temp;
	size_t		i;
	size_t		j;

	temp = a->top;
	i = 0;
	while (i < (size_t)a->size)
	{
		j = 0;
		while (sorted_arr[j] != temp->value)
			j++;
		temp->compressed_value = j;
		temp = temp->next;
		i++;
	}
}

// Calculate the compressed index by directly comparing the elements of stack a

void	compress_idx(t_stack *a)
{
	int	*sorted_arr;

	sorted_arr = (int *)malloc(sizeof(int) * (a->size));
	if (!sorted_arr)
		malloc_error();
	printf("Address3: %p\n", (void*)sorted_arr);
	copy_stack_to_array(a, sorted_arr);
	bubble_sort(sorted_arr, a->size);
	set_compressed_idx(a, sorted_arr);
	free(sorted_arr);
}

void	sort_large(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size_a_init;

	i = 0;
	size_a_init = a->size;
	while (!is_stack_sorted(a))
	{
		j = 0;
		while (j++ < size_a_init)
		{
			if ((a->top->compressed_value >> i) & 1)
				rotate_a(a);
			else
				push_b(a, b);
		}
		while (b->size > 0)
			push_a(a, b);
		i++;
	}
}
