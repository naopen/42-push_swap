/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:19:12 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/01 12:05:45 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	args_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	malloc_error(void)
{
	exit(1);
}
