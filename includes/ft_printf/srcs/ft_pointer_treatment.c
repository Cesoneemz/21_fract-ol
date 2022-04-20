/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_treatment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:16:04 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/18 20:43:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "../includes/ft_printf.h"

int	ft_pointer_treatment(unsigned long long addr)
{
	char	*ptr;
	int		index;

	index = 0;
	ptr = ft_convert_to_base(addr, 16);
	ptr = ft_tolower_str(ptr);
	index += ft_putstr("0x", 2);
	index += ft_putstr(ptr, ft_strlen(ptr));
	free(ptr);
	return (index);
}
