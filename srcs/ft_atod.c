/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:47:48 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/20 20:04:25 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f' \
			|| c == '\v');
}

int	ft_is_double(char *c)
{
	while (*c)
	{
		if (*c != '-' && *c != '.' && !ft_isdigit(*c))
			return (1);
		c++;
	}
	return (0);
}

double	ft_atod(const char *str)
{
	double	result;
	double	result2;
	char	*c;
	int		len;
	int		minus;

	c = (char *)str;
	minus = 1;
	result = (double)ft_atoi(c);
	while (ft_isspace(*c))
		c++;
	if (*c == '-')
		minus *= -1;
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	result2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		result2 /= 10;
	if (minus != -1)
		return (result + result2);
	else
		return (result - result2);
}
