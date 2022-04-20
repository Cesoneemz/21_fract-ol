/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:09:01 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/13 17:19:20 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int	ft_get_words_count(const char *str, char del)
{
	int	index;

	index = 0;
	while (*str == del && *str)
		str++;
	while (*str != '\0')
	{
		if (((*str == del) && (*(str + 1) != del)) || \
			(*(str + 1) == '\0' && ft_isalnum(*(str - 1))))
			index++;
		str++;
	}
	if (index == 0 && ft_isalnum(*(str - 1)))
		index++;
	if (index == 0 && *str == '\0')
		return (0);
	return (index);
}

static int	ft_get_word_len(char const *s, char c)
{
	int	index;

	index = 0;
	while (*s != c && *s != '\0')
	{
		index++;
		s++;
	}
	return (index);
}

static char	**ft_buffer_free(char **buffer)
{
	unsigned int	index;

	index = 0;
	while (buffer[index])
	{
		free(buffer[index]);
		index++;
	}
	free(buffer);
	return (NULL);
}

static char	**ft_split_in_buffer(char const *s, char c, \
									int c_words, char **buffer)
{
	int		index;
	int		jndex;
	int		word_len;

	index = -1;
	while (index++ < c_words - 1)
	{
		jndex = -1;
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0' && *(s - 1) == c)
			break ;
		word_len = ft_get_word_len(s, c);
		buffer[index] = (char *)malloc((word_len + 1) * sizeof(char));
		if (buffer[index] == NULL)
			return (ft_buffer_free(buffer));
		while (jndex++ < word_len - 1 && *s != c)
			buffer[index][jndex] = *s++;
		buffer[index][jndex] = '\0';
	}
	buffer[c_words] = 0;
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		c_words;

	if (!s)
		return (NULL);
	c_words = ft_get_words_count(s, c);
	buffer = (char **)malloc((c_words + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	if (c_words == 0)
		buffer[c_words] = 0;
	else
		buffer = ft_split_in_buffer(s, c, c_words, buffer);
	return (buffer);
}
