/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:23:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 18:09:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

int		ft_absolute_value_i(int number)
{
	return (ft_absolute_value(number));
}

float	ft_absolute_value_f(float number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

double	ft_absolute_value_d(double number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

double	smallest_d(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}

double	largest_d(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

double	degrees_to_radians(double degrees)
{
	const double pi = RTPI;

	return (degrees * pi) / 180.0;
}
