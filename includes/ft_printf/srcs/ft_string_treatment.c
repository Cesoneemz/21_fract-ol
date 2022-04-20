/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_string_treatment(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		str = "(null)";
	index += ft_putstr(str, ft_strlen(str));
	return (index);
}
