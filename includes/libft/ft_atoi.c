/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:07:33 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/06 21:45:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f' \
			|| c == '\v');
}

static int	ft_get_result_if_overflow(int minus)
{
	if (minus > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					minus;
	size_t				counter;

	result = 0;
	minus = 1;
	counter = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		minus *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if (result >= 9223372036854775808ULL || counter >= 25)
			return (ft_get_result_if_overflow(minus));
		counter++;
		str++;
	}
	return ((int)result * minus);
}
