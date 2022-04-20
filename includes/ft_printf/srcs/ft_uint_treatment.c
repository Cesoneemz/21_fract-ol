/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:54:43 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:55:31 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../includes/ft_printf.h"

int	ft_uint_treatment(unsigned int nbr)
{
	int				index;
	char			*buffer;

	index = 0;
	buffer = ft_uint_itoa(nbr);
	index += ft_putstr(buffer, ft_strlen(buffer));
	free(buffer);
	return (index);
}
