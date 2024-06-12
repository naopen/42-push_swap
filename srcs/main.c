/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:02:15 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/12 23:42:34 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	parse_args(t_sort_env *data, int argc, char *argv[])
{
	int			i;
	long		value;
	char		*endptr;

	i = 1;
	while (i < argc)
	{
		value = ft_strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || value > INT_MAX || value < INT_MIN)
			args_error();
		value_to_stack(&data->a, (int)value);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_sort_env	*data;

	validate_args(argc, argv);
	data = data_init();
	parse_args(data, argc, argv);
	compress_idx(&data->a);
	sort(&data->a, &data->b);
	free_data(data);
	return (0);
}
