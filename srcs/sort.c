/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:57:14 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 04:30:44 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_sort_env *data)
{
	int	size;

	size = stack_size(&data->a);
	if (size == 2)
		sort_two(&data->a);
	else if (size == 3)
		sort_three(&data->a);
	else if (size >= 4 && size <= 6)
		sort_four_to_six(&data->a, &data->b);
	else if (size >= 7)
		sort_large(data);
}
