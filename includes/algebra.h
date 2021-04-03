/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:19:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 17:28:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <float.h>

typedef struct	s_quadratic_result
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	d_sqrt;
	double	root;
}				t_quadratic_result;

double			infinity(void);
double			pi(void);

double			degrees_to_radians(double degrees);
bool			quadratic(t_quadratic_result r,
							double min_translation,
							double max_translation,
							double *root);
double			schlicks_approximation(double cosine, double refraction_ratio);

#endif
