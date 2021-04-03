/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_geometry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:40:56 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

bool		near_zero(t_vector_3d vector)
{
	const float cuttoff = 1e-8;
	bool cuts_off_x = ft_abs_d(vector.x) < cuttoff;
	bool cuts_off_y = ft_abs_d(vector.y) < cuttoff;
	bool cuts_off_z = ft_abs_d(vector.z) < cuttoff;
	return (cuts_off_x && cuts_off_y && cuts_off_z);
}

t_vector_3d	reflect(const t_vector_3d incident, const t_vector_3d normal)
{
	double factor = 2.0 * dot(incident, normal);
	t_vector_3d complement = scalar_times(factor, normal);
	return (sub(incident, complement));
}

t_vector_3d	refract(const t_vector_3d incident,
					const t_vector_3d normal,
					double refration_ration)
{
	double cos_theta = dot(negative(incident), normal);
	cos_theta = ft_min_d(cos_theta, 1.0);
	t_vector_3d refracted_perpendicular = add(incident, scalar_times(cos_theta, normal));
	refracted_perpendicular = scalar_times(refration_ration, refracted_perpendicular);

	double parallel_magnitude = 1.0 - length_squared(refracted_perpendicular);
	parallel_magnitude = ft_abs_d(parallel_magnitude);
	parallel_magnitude = -sqrt(parallel_magnitude);
	t_vector_3d refracted_parallel = scalar_times(parallel_magnitude, normal);

	t_vector_3d refracted = add(refracted_perpendicular, refracted_parallel);
	return (refracted);
}
