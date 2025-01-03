/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:23:38 by khoukouj          #+#    #+#             */
/*   Updated: 2025/01/03 13:12:49 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->iterations = 70;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, 2, 0, key_handler, fractal);
	mlx_hook(fractal->win, 17, 0, ft_close_handler, fractal);
	mlx_hook(fractal->win, 4, 0, ft_mouse_handler, fractal);
}

void	fractol_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, \
									HEIGHT, fractal->name);
	if (!fractal->win)
		exit(EXIT_FAILURE);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		exit(EXIT_FAILURE);
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, \
												&fractal->img.bits_per_pixel, \
												&fractal->img.line_len, \
												&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
