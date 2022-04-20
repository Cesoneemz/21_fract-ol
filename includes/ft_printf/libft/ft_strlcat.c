/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:07:33 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/06 21:45:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	char	*str;
	size_t	dstlen;
	size_t	srclen;
	size_t	size;
	size_t	result;

	size = 0;
	str = (char *)s;
	dstlen = ft_strlen(d);
	srclen = ft_strlen(s);
	if (dstsize > dstlen)
		result = srclen + dstlen;
	else
		result = srclen + dstsize;
	while (str[size] && (dstlen + 1) < dstsize)
	{
		d[dstlen] = str[size];
		dstlen++;
		size++;
	}
	d[dstlen] = '\0';
	return (result);
}
