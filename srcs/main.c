/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:49 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/26 10:54:23 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_show_aviable_args(void)
{
	ft_printf("%s\n", \
	"------------------------------------------------------------");
	ft_printf("%s\n", \
	"| Commands:                                                |");
	ft_printf("%s\n", \
	"| ./fractol Mandelbrot                      Draw Mandelbrot|");
	ft_printf("%s\n", \
	"| ./fractol Julia                                Draw Julia|");
	ft_printf("%s\n", \
	"| ./fractol Julia <re> <im>   Draw Julia with custom params|");
	ft_printf("%s\n", \
	"| ./fractol Mandelbar                        Draw Mandelbar|");
	ft_printf("%s\n", \
	"| ./fractol Perpendicular_Burning_Ship    Draw Burning ship|");
	ft_printf("%s\n", \
	"| ./fractol Horizontal_Mandelbar  Draw Horizontal Mandelbar|");
	ft_printf("%s\n", \
	"------------------------------------------------------------");
	exit(0);
}

void	ft_draw_fractol(t_fractol *fractol)
{
	int			a;
	int			b;
	t_complex	factor;

	factor = ft_init_complex((fractol->max.re - fractol->min.re) / (WIDTH),
			(fractol->max.im - fractol->min.im) / (HEIGHT));
	b = 0;
	while (b < HEIGHT)
	{
		fractol->c.im = fractol->max.im - b * factor.im;
		a = 0;
		while (a < WIDTH)
		{
			fractol->c.re = fractol->min.re + a * factor.re;
			fractol->formula(fractol);
			ft_pixel_put(fractol, a, b, ft_init_color(fractol));
			a++;
		}
		b++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->img, 0, 0);
}

static void	ft_start_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	fractol->image = ft_image_init(fractol);
	mlx_hook(fractol->window, KEY_PRESS, 1L << 0, ft_keys_treatment, fractol);
	mlx_hook(fractol->window, MOUSE_PRESS, 1L << 2, ft_mouse_control, fractol);
	mlx_hook(fractol->window, DESTROY, 0, ft_close, fractol);
	if (fractol->formula == &julia)
		mlx_hook(fractol->window, MOUSE_MOTION, 1L << 6, \
		ft_change_julia, fractol);
	ft_draw_fractol(fractol);
	mlx_loop(fractol->mlx);
}

static void	ft_parse_argv(char *argv, t_fractol *fractol)
{
	ft_init_default(fractol);
	if (!(ft_strncmp(argv, "Mandelbrot", 12)))
		fractol->formula = &mandelbrot;
	else if (!(ft_strncmp(argv, "Julia", 6)))
		fractol->formula = &julia;
	else if (!(ft_strncmp(argv, "Mandelbar", 10)))
		fractol->formula = &mandelbar;
	else if (!(ft_strncmp(argv, "Perpendicular_Burning_Ship", 27)))
		fractol->formula = &p_burning_ship;
	else if (!(ft_strncmp(argv, "Horizontal_Mandelbar", 21)))
		fractol->formula = &horizontal_mandelbar;
	if (fractol->formula != NULL)
		ft_start_fractol(fractol);
	else
	{
		free(fractol);
		ft_show_aviable_args();
	}
	free(fractol);
}

int	main(int argc, char *argv[])
{
	t_fractol		*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		exit(EXIT_FAILURE);
	if (argc == 2)
		ft_parse_argv(argv[1], fractol);
	else if (argc == 4)
	{
		if (!(ft_strncmp(argv[1], "Julia", 6)))
		{
			ft_init_default(fractol);
			if (ft_is_double(argv[2]) || ft_is_double(argv[3]))
				ft_show_aviable_args();
			fractol->k = ft_init_complex(ft_atod(argv[2]), ft_atod(argv[3]));
			fractol->formula = &julia;
			ft_start_fractol(fractol);
		}
		else
			ft_show_aviable_args();
	}
	else
		ft_show_aviable_args();
	exit(EXIT_SUCCESS);
	return (0);
}
