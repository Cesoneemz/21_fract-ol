/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:10:58 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/20 19:48:17 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	ft_fractol_zoom(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	ft_mouse_control(int key, int x, int y, t_fractol *fractol)
{	
	t_complex	mouse;
	double		zoom;

	if (key == MOUSE_BUTTON)
		fractol->press = !fractol->press;
	mouse.re = (fractol->min.re + x
			* ((fractol->max.re - fractol->min.re) / (WIDTH)));
	mouse.im = (fractol->max.im - y
			* ((fractol->max.im - fractol->min.im) / (HEIGHT)));
	if (key == 5)
		zoom = 1.20;
	else if (key == 4)
		zoom = 0.80;
	else
		zoom = 1.0;
	fractol->min.re = ft_fractol_zoom(mouse.re, fractol->min.re, zoom);
	fractol->min.im = ft_fractol_zoom(mouse.im, fractol->min.im, zoom);
	fractol->max.re = ft_fractol_zoom(mouse.re, fractol->max.re, zoom);
	fractol->max.im = ft_fractol_zoom(mouse.im, fractol->max.im, zoom);
	fractol->max_iter *= 1.1;
	ft_draw_fractol(fractol);
	return (0);
}

int	ft_change_julia(int x, int y, t_fractol *fractol)
{
	if (fractol->press == 1)
	{
		fractol->k = ft_init_complex(
				4 * ((double)x / WIDTH - 0.5),
				4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		ft_draw_fractol(fractol);
	}
	return (0);
}
