/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:54:00 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:55:23 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../includes/ft_printf.h"

static char	*ft_base_treatment(unsigned long long addr, int base, \
char *buffer, int index)
{
	while (addr != 0)
	{
		if ((addr % base) < 10)
			buffer[index - 1] = (addr % base) + 48;
		else
			buffer[index - 1] = (addr % base) + 55;
		addr /= base;
		index--;
	}
	return (buffer);
}

char	*ft_convert_to_base(unsigned long long addr, int base)
{
	char				*buffer;
	int					index;
	unsigned long long	original_addr;

	if (addr == 0)
		return (ft_strdup("0"));
	original_addr = addr;
	index = 0;
	while (addr != '\0')
	{
		addr /= base;
		index++;
	}
	buffer = malloc((index + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[index] = '\0';
	buffer = ft_base_treatment(original_addr, base, buffer, index);
	return (buffer);
}
