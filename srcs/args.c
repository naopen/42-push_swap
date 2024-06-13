/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:01:48 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/13 21:43:29 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_input_integer(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_input_sorted(int argc, char *argv[])
{
	int	i;
	int	prev;

	i = 1;
	if (argc > 2)
	{
		prev = ft_atoi(argv[i++]);
		while (i < argc)
		{
			if (prev >= ft_atoi(argv[i]))
				return (0);
			prev = ft_atoi(argv[i++]);
		}
	}
	return (1);
}

static int	has_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_memcmp(argv[i], argv[j], ft_strlen(argv[i]) + 1) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_args(int argc, char *argv[])
{
	int	i;

	if (!is_input_integer(argc, argv))
		args_error();
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (is_input_sorted(argc, argv))
		exit(EXIT_SUCCESS);
	if (has_duplicates(argc, argv))
		args_error();
	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
			args_error();
		i++;
	}
}
