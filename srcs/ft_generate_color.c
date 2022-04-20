/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:43:29 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/20 13:54:20 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->image->addr + (y * fractol->image->line_len
			+ x * (fractol->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_init_color(t_fractol *fractol)
{
	double	t;
	int		color[4];

	t = (double)fractol->iter / (double)fractol->max_iter;
	color[0] = 0;
	if (fractol->color == 1)
	{
		color[2] = (int)(9.6 * (1 - t) * pow(t, 3) * 255);
		color[1] = (int)(12 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(7.2 * pow((1 - t), 3) * t * 255);
	}
	if (fractol->color == 2)
	{
		color[3] = (int)(9.6 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(12 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[1] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (fractol->color == 3)
	{
		color[2] = (int)(13 * (1 - t) * pow(t, 3) * 255);
		color[3] = (int)(64 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[1] = (int)(4.5 * pow((1 - t), 3) * t * 255);
	}
	return (ft_create_trgb(color[0], color[1], color[2], color[3]));
}
