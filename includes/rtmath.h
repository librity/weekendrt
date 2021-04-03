/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:19:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 14:46:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTMATH_H
# define RTMATH_H

# include <float.h>

# define RTINFINITY DBL_MAX;
# define RTPI 3.1415926535897932385;

typedef struct	s_quadratic_result
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	d_sqrt;
	double	root;
}				t_quadratic_result;

double			degrees_to_radians(double degrees);
bool			quadratic(t_quadratic_result r,
							double min_translation,
							double max_translation,
							double *root);
double			schlicks_approximation(double cosine, double refraction_ratio);

#endif
