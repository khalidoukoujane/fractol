/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khoukouj <khoukouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:14:02 by khoukouj          #+#    #+#             */
/*   Updated: 2025/01/01 15:48:19 by khoukouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

static int	integral_part(char **s)
{
	int	res;

	res = 0;
	while (**s && **s != '.')
	{
		res = res * 10 + (**s - 48);
		(*s)++;
	}
	return (res);
}

static	double	fractional_part(char *s)
{
	double	frac;
	double	res;

	frac = 1;
	res = 0;
	if (*s)
		s++;
	while (*s)
	{
		frac /= 10;
		res += (*s - 48) * frac;
		s++;
	}
	return (res);
}

double	ft_atof(char *s)
{
	int		int_part;
	double	frac_part;
	int		sign;

	sign = 1;
	while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	int_part = integral_part(&s);
	frac_part = fractional_part(s);
	return ((int_part + frac_part) * sign);
}
