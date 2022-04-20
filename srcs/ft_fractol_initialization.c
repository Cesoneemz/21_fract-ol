/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_initialization.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:28:19 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/20 15:16:47 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	ft_init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_image	*ft_image_init(t_fractol *fractol)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (0);
	image->img = mlx_new_image(fractol->mlx, HEIGHT, WIDTH);
	image->addr = mlx_get_data_addr(image->img,
			&(image->bits_per_pixel), &(image->line_len),
			&(image->endian));
	return (image);
}

void	ft_init_default(t_fractol *fractol)
{
	fractol->max_iter = 50;
	fractol->min = ft_init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) \
		* (HEIGHT / WIDTH);
	fractol->color = 1;
	fractol->press = 0;
	fractol->formula = NULL;
}
