/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:02:15 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/21 06:16:45 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	parse_args(t_sort_env *data, int argc, char *argv[])
{
	int		i;
	int		j;
	int		value;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			value = ft_atoi(&argv[i][j]);
			if (value > INT_MAX || value < INT_MIN)
			{
				printf("value: %d\n", value);
				args_error();
			}
			value_to_stack(&data->a, value);
			while (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
				j++;
			while (argv[i][j] == ' ')
				j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_sort_env	*data;

	validate_args(argc, argv);
	data = data_init();
	parse_args(data, argc, argv);
	sort(&data->a, &data->b);
	free_data(data);
	return (0);
}
