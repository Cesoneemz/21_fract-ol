/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:15:34 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/06 21:45:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buffer;
	int				strlen;
	unsigned int	index;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	buffer = (char *)malloc((strlen + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (*s)
	{
		buffer[index] = (*f)(index, *s++);
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}
