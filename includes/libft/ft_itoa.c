/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:16:04 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/13 18:52:50 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	ft_get_nbr_len(int n)
{
	size_t	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		size;

	size = ft_get_nbr_len(n);
	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (n < 0)
		buffer[0] = '-';
	else
		buffer[0] = '0';
	buffer[size] = '\0';
	while (n != 0)
	{
		size--;
		buffer[size] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (buffer);
}
