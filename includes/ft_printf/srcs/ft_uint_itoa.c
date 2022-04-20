/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:54:50 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:55:29 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../includes/ft_printf.h"

static int	ft_get_uint_len(long nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr >= 1)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static char	*ft_uint_itoa_proceed(char *buffer, long nbr, int len)
{
	int	bool_negative;

	bool_negative = 0;
	if (nbr != 0)
		buffer = malloc((len + 1) * sizeof(char));
	else
		return (ft_strdup("0"));
	if (!buffer)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		bool_negative = 1;
	}
	buffer[len] = '\0';
	while (--len)
	{
		buffer[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (bool_negative)
		buffer[0] = '-';
	else
		buffer[0] = (nbr % 10) + '0';
	return (buffer);
}

char	*ft_uint_itoa(unsigned int nbr)
{
	int		len;
	char	*buffer;
	long	n;

	n = nbr;
	len = ft_get_uint_len(n);
	buffer = 0;
	buffer = ft_uint_itoa_proceed(buffer, nbr, len);
	if (!buffer)
		return (NULL);
	return (buffer);
}
