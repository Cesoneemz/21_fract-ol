/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:07:33 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/13 18:44:39 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t dstsize)
{
	size_t	index;

	if (dstsize == 0)
		return (ft_strlen(s));
	index = 0;
	while (s[index] != '\0' && index < dstsize - 1)
	{
		d[index] = s[index];
		index++;
	}
	d[index] = '\0';
	return (ft_strlen(s));
}
