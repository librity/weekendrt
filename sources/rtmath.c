/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtmath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 03:23:51 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 14:25:01 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

double	degrees_to_radians(double degrees)
{
	const double pi = RTPI;

	return (degrees * pi) / 180.0;
}

bool	quadratic(t_quadratic_result r,
					double min_translation,
					double max_translation,
					double *root)
{
	r.discriminant = r.half_b * r.half_b - r.a * r.c;
	if (r.discriminant < 0)
		return (false);
	r.d_sqrt = sqrt(r.discriminant);
	r.root = (-r.half_b - r.d_sqrt) / r.a;
	if (r.root < min_translation || max_translation < r.root)
	{
		r.root = (-r.half_b + r.d_sqrt) / r.a;
		if (r.root < min_translation || max_translation < r.root)
			return (false);
	}
	*root = r.root;
	return (true);
}

double	schlicks_approximation(double cosine, double refraction_ratio)
{
	double coefficient = (1 - refraction_ratio) / (1 + refraction_ratio);
	coefficient = coefficient * coefficient;
	coefficient = coefficient + (1 - coefficient) * pow((1 - cosine), 5);
	return (coefficient);
}
