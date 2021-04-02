/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:19:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 01:15:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTMATH_H
# define RTMATH_H

# include <float.h>

# define RTINFINITY DBL_MAX;
# define RTPI 3.1415926535897932385;

int		ft_absolute_value_i(int number);
float	ft_absolute_value_f(float number);

double	degrees_to_radians(double degrees);
double	clamp(double x, double min, double max);

#endif
