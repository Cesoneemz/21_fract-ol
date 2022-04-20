/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "../includes/ft_printf.h"

int	ft_printf_parse(const char *input, va_list argptr)
{
	int		index;
	int		counter;

	counter = 0;
	index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == '%' && input[index])
		{
			index++;
			if (ft_type_is_valid(input[index]))
				counter += ft_printf_split_by_args(input[index], argptr);
			else if (input[index])
				counter += ft_putchar(input[index]);
		}
		else if (!ft_type_is_valid(input[index]))
			counter += ft_putchar(input[index]);
		index++;
	}
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	argptr;
	int		counter;

	counter = 0;
	va_start(argptr, input);
	counter += ft_printf_parse(input, argptr);
	va_end(argptr);
	return (counter);
}
