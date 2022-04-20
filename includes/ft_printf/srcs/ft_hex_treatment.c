/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:50:14 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:05 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../includes/ft_printf.h"

int	ft_hex_treatment(unsigned int nbr, char c)
{
	int				index;
	char			*buffer;

	index = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	buffer = ft_convert_to_base((unsigned long long)nbr, 16);
	if (c == 'x')
		buffer = ft_tolower_str(buffer);
	index += ft_putstr(buffer, ft_strlen(buffer));
	free(buffer);
	return (index);
}
