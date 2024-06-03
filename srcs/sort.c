/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:57:14 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/19 21:57:21 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (stack_size(a) == 2)
		sort_two(a);
	else if (stack_size(a) == 3)
		sort_three(a);
	else if (stack_size(a) >= 4 && stack_size(a) <= 6)
		sort_four_to_six(a, b);
	else if (stack_size(a) >= 7)
		sort_large(a, b);
	else
		return ;
}
