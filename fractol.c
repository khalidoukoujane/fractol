/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:33:45 by khoukouj          #+#    #+#             */
/*   Updated: 2025/01/01 17:01:10 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	invalid_nums(char *s)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] != '.' && (s[i] < '0' || s[i] > '9'))
			return (1);
		if (s[i] == '.')
			point++;
		i++;
	}
	if (point > 1)
		return (1);
	return (0);
}

void	ft_print_usage(void)
{
	ft_putstr_fd("usage:\n\t./fractol mandelbrot\n", 2);
	ft_putstr_fd("\t./fractol julia <r> <im> (between -2 and 2)\n", 2);
	exit(EXIT_FAILURE);
}

void	parse_input(int ac, char **av, t_fractal *fractal)
{
	if (ac <= 1)
		ft_print_usage();
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		fractal->name = av[1];
		return ;
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia") \
			&& !invalid_nums(av[2]) && !invalid_nums(av[3]))
	{
		fractal->name = av[1];
		fractal->julia_r = ft_atof(av[2]);
		fractal->julia_im = ft_atof(av[3]);
		if (ft_atof(av[2]) > 2 || ft_atof(av[2]) < -2
			|| ft_atof(av[3]) > 2 || ft_atof(av[3]) < -2)
			(ft_putstr_fd("Invalid coords\n", 2), exit(1));
	}
	else
		ft_print_usage();
}

int	main(int ac, char *av[])
{
	t_fractal	fractal;

	parse_input(ac, av, &fractal);
	fractol_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
