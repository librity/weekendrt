/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:19:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 18:54:18 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTMATH_H
# define RTMATH_H

# include <float.h>

# define RTINFINITY DBL_MAX;
# define RTPI 3.1415926535897932385;

int		ft_absolute_value_i(int number);
float	ft_absolute_value_f(float number);
double	ft_absolute_value_d(double number);

double	smallest_d(double x, double y);
double	largest_d(double x, double y);
double	clamp(double x, double min, double max);

double	degrees_to_radians(double degrees);

#endif
