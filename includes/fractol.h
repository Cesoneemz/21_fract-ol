/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:36:48 by wlanette          #+#    #+#             */
/*   Updated: 2022/04/20 20:00:00 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/includes/ft_printf.h"

/* DEFINES */

# define WIDTH 				800
# define HEIGHT 			800

# define KEY_PRESS 			2
# define MOUSE_PRESS 		4
# define MOUSE_MOTION 		6

# define MOUSE_ZOOM_PLUS	5
# define MOUSE_ZOOM_MINUS	4
# define MOUSE_BUTTON		1

# define KEY_ARROW_LEFT		123
# define KEY_ARROW_UP		126
# define KEY_ARROW_RIGHT	124
# define KEY_ARROW_DOWN		125

# define C_BUTTON			8
# define ESC				53
# define DESTROY			17

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_image;

typedef struct s_fractol
{
	void						(*formula)(struct s_fractol *);
	void						*mlx;
	void						*window;
	unsigned long long			iter;
	unsigned long long			max_iter;
	int							color;
	int							press;
	t_complex					max;
	t_complex					min;
	t_complex					c;
	t_complex					k;
	t_image						*image;
}				t_fractol;

/* CONTROLS */

int			ft_keys_treatment(int keycode, t_fractol *fractol);
int			ft_mouse_control(int key, int x, int y, t_fractol *fractol);

/* FRACTAL TREATMENT */

t_image		*ft_image_init(t_fractol *fractol);
t_complex	ft_init_complex(double re, double im);
void		ft_init_default(t_fractol *fractol);
void		ft_draw_fractol(t_fractol *fractol);
int			ft_close(void *param);
int			ft_is_double(char *c);
double		ft_atod(const char *str);

/* MLX FUNCTIONS */

int			ft_init_color(t_fractol *fractol);
void		ft_pixel_put(t_fractol *fractol, int x, int y, int color);

/* FRACTALS */

void		mandelbrot(t_fractol *fractol);
void		julia(t_fractol *fractol);
void		mandelbar(t_fractol *fractol);
void		p_burning_ship(t_fractol *fractol);
int			ft_change_julia(int x, int y, t_fractol *fractol);
void		horizontal_mandelbar(t_fractol *fractol);

#endif
