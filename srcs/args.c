/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:01:48 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/04 04:02:02 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(int argc, char *argv[])
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
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_integer(char *str)
{
	long	num;
	char	*tmp;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	tmp = ft_itoa(num);
	if (ft_strcmp(str, tmp) != 0)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

void	validate_args(int argc, char *argv[])
{
	int	i;

	if (argc <= 2 || is_sorted(argc, argv) || has_duplicates(argc, argv))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
