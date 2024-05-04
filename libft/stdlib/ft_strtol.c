/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:22:34 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/05 08:29:06 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// ——About strtol——
// If it overflows, LONG_MAX or LONG_MIN is returned.

// static int	ft_isspace(char c)
// {
// 	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
// 		|| c == ' ')
// 		return (1);
// 	return (0);
// }

// Function to determine if 'num' will overflow
static int	ft_is_overflow(unsigned long long num, int sign, unsigned int digit)
{
	if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && digit > LONG_MAX % 10))
	{
		if (sign == 1)
			return (1);
		else
			return (-1);
	}
	return (0);
}

long	ft_strtol(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (ft_is_overflow(num, sign, *str - '0'))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		num = num * 10 + (*str++ - '0');
	}
	return (num * sign);
}
