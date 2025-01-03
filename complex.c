/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:01:43 by khoukouj          #+#    #+#             */
/*   Updated: 2025/01/03 14:27:26 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scal_down(double value, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (value - old_min) \
			/ (old_max - old_min) + new_min);
}

t_cmplx	sum_cmplx(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	res;

	res.real = z1.real + z2.real;
	res.img = z1.img + z2.img;
	return (res);
}

t_cmplx	square_cmplx(t_cmplx z)
{
	t_cmplx	res;

	res.real = (z.real * z.real) - (z.img * z.img);
	res.img = 2 * z.real * z.img;
	return (res);
}
