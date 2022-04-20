/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:36:42 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/13 18:42:18 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*buffer;
	unsigned int	strlen;
	unsigned int	index;

	strlen = ft_strlen(s1);
	buffer = malloc((strlen + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
		buffer[index++] = *s1++;
	buffer[index] = '\0';
	return (buffer);
}
