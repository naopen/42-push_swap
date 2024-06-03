/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 04:01:48 by nkannan           #+#    #+#             */
/*   Updated: 2024/06/04 03:51:13 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static int	is_sorted(int argc, char *argv[])
// {
// 	int	i;
// 	int	prev;

// 	i = 1;
// 	if (argc > 2)
// 	{
// 		prev = ft_atoi(argv[i++]);
// 		while (i < argc)
// 		{
// 			if (prev >= ft_atoi(argv[i]))
// 				return (0);
// 			prev = ft_atoi(argv[i++]);
// 		}
// 	}
// 	return (1);
// }

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

	if (argc == 1)
		exit(0);
	// is_sorted(argc, argv);
	if (has_duplicates(argc, argv))
	{
		// printf("Error\n");
		args_error();
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
		{
			// printf("%s\n", argv[i]);
			args_error();
		}
		i++;
	}
}

// void	validate_args(int argc, char *argv[])
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		j = 0;
// 		if (argv[i][j] == '-' || argv[i][j] == '+')
// 			j++;
// 		while (argv[i][j])
// 		{
// 			if (!ft_isdigit(argv[i][j]))
// 				args_error();
// 			j++;
// 		}
// 		j = 1;
// 		while (j < argc)
// 		{
// 			if (j != i && !ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]) + 1))
// 				args_error();
// 			j++;
// 		}
// 		i++;
// 	}
// }
