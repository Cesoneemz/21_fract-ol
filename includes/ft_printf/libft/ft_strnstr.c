/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:07:33 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/06 21:45:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	jndex;

	index = 0;
	jndex = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[index] != '\0' && len)
	{
		if (haystack[index] == needle[0])
		{
			while (needle[jndex] != '\0' && \
			needle[jndex] == haystack[index + jndex] && (index + jndex < len))
			{
				if (needle[jndex + 1] == '\0')
					return ((char *)&haystack[index]);
				jndex++;
			}
		}
		index++;
	}
	return (NULL);
}
