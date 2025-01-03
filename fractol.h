/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:32 by khoukouj          #+#    #+#             */
/*   Updated: 2025/01/02 21:29:55 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000

typedef struct s_cmplx
{
	double	real;
	double	img;
}			t_cmplx;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	char	*name;
	int		iterations;
	double	zoom;
	double	julia_r;
	double	julia_im;
	t_img	img;
}			t_fractal;

//utils
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
double	ft_atof(char *s);
//fractol stuff
void	fractol_init(t_fractal *fractal);
int		ft_generat_color(int i, int max_iterations);
void	fractal_render(t_fractal *fractal);
// math utils
t_cmplx	square_cmplx(t_cmplx z);
t_cmplx	sum_cmplx(t_cmplx z1, t_cmplx z2);
double	scal_down(double value, double new_min, double new_max, double old_max);
//events
int		key_handler(int keycode, t_fractal *fractal);
int		ft_close_handler(t_fractal *fractal);
int		ft_mouse_handler(int keycode, int x, int y, t_fractal *fractal);
#endif