/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:32:14 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/06 21:45:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	ft_char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_get_len_without_set(char const *s, char const *set)
{
	int	s_len;
	int	index;
	int	jndex;

	s_len = ft_strlen(s);
	index = 0;
	jndex = s_len - 1;
	while (ft_char_in_set(s[index], set))
	{
		index++;
		s_len--;
	}
	while (ft_char_in_set(s[jndex], set))
	{
		jndex--;
		s_len--;
	}
	if (s_len < 0)
		s_len = -s_len;
	return (s_len);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*buffer;
	int		s_len;
	int		index;

	if (!s || !set)
		return (NULL);
	s_len = ft_get_len_without_set(s, set);
	buffer = (char *)malloc((s_len + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (ft_char_in_set(*s, set))
		s++;
	while (index < s_len)
	{
		buffer[index] = *s++;
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}
