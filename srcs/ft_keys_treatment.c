/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:14:24 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/26 10:58:52 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close(void *param)
{
	(void)param;
	exit(0);
}

void	ft_color_fractol(t_fractol *fractol)
{
	fractol->color++;
	if (fractol->color > 3)
		fractol->color = 1;
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static void	ft_move(int keycode, t_fractol *fractol)
{
	t_complex	z;

	z = ft_init_complex(ft_abs(fractol->max.re - fractol->min.re), \
						ft_abs(fractol->max.im - fractol->min.im));
	if (keycode == KEY_ARROW_LEFT)
	{
		fractol->max.re -= z.re * 0.05;
		fractol->min.re -= z.re * 0.05;
	}
	else if (keycode == KEY_ARROW_RIGHT)
	{
		fractol->max.re += z.re * 0.05;
		fractol->min.re += z.re * 0.05;
	}
	else if (keycode == KEY_ARROW_DOWN)
	{
		fractol->min.im -= z.im * 0.05;
		fractol->max.im -= z.im * 0.05;
	}
	else if (keycode == KEY_ARROW_UP)
	{
		fractol->min.im += z.im * 0.05;
		fractol->max.im += z.im * 0.05;
	}
}

int	ft_keys_treatment(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		ft_close(fractol);
	else if (keycode == C_BUTTON)
		ft_color_fractol(fractol);
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_ARROW_UP \
			|| keycode == KEY_ARROW_RIGHT || keycode == KEY_ARROW_DOWN)
		ft_move(keycode, fractol);
	ft_draw_fractol(fractol);
	return (0);
}
