/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkannan <nkannan@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:31:54 by nkannan           #+#    #+#             */
/*   Updated: 2024/05/05 08:32:30 by nkannan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isinteger(char *str)
{
	long	num;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (ft_strlen(str) > 11)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	num = ft_strtol(str);
	if (num < INT_MIN || INT_MAX < num)
		return (0);
	return (1);
}
