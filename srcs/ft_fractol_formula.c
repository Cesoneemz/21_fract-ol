/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_formula.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:02:27 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/20 13:48:19 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fractol *fractol)
{
	t_complex	z;

	z = ft_init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter < fractol->max_iter)
	{
		z = ft_init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->c.re, 2.0 * z.re * z.im + fractol->c.im);
		fractol->iter++;
	}
}

void	julia(t_fractol *fractol)
{
	t_complex	z;

	z = ft_init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter < fractol->max_iter)
	{
		z = ft_init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->k.re, 2.0 * z.re * z.im + fractol->k.im);
		fractol->iter++;
	}
}

void	mandelbar(t_fractol *fractol)
{
	t_complex	z;

	z = ft_init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter < fractol->max_iter)
	{
		z = ft_init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
				-2.0 * z.re * z.im + fractol->c.im);
		fractol->iter++;
	}
}

void	p_burning_ship(t_fractol *fractol)
{
	t_complex	z;

	z = ft_init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter < fractol->max_iter)
	{
		z = ft_init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
				-2.0 * z.re * fabs(z.im) + fractol->c.im);
		fractol->iter++;
	}
}

void	horizontal_mandelbar(t_fractol *fractol)
{
	t_complex	z;

	z = ft_init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter < fractol->max_iter)
	{
		z = ft_init_complex(z.re * (pow(pow(z.re, 2.0), 2.0) - 10.0 * \
		pow(z.re, 2.0) * pow(z.im, 2.0) + 5 * \
		pow(pow(z.im, 2.0), 2.0)) + fractol->c.re, \
		-z.im * (5.0 * pow(pow(z.re, 2.0), 2.0) - 10.0 * \
		pow(z.re, 2.0) * pow(z.im, 2.0) + \
		pow(pow(z.im, 2.0), 2.0)) + fractol->c.im);
		fractol->iter++;
	}
}
