/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 04:02:15 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 08:02:20 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	parse_args(t_sort_env *data, int argc, char *argv[])
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
				args_error();
			value_to_stack(&data->a, value);
			while (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
				j++;
			while (argv[i][j] == ' ')
				j++;
		}
		i++;
	}
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}

void check_mem(t_sort_env *data)
{
	t_node *temp;
	temp = data->a.top;
	while (temp)
	{
		printf("Address5: %p\n", (void*)temp);
		temp = temp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_sort_env	*data;

	validate_args(argc, argv);
	data = data_init();
	check_mem(data);
	parse_args(data, argc, argv);
	check_mem(data);
	compress_idx(&data->a);
	check_mem(data);
	sort(&data->a, &data->b);
	check_mem(data);
	free_node(&data->a);
	free_data(data);
	exit (0);
}
