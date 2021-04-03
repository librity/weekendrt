/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:23:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 15:56:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_material	*make_dielectric(double refraction_index)
{
	t_material *new;

	new = prototype_material(&scatter_dielectric);
	new->refraction_index = refraction_index;
	return (new);
}

bool		scatter_dielectric(t_ray incident_ray,
								void *void_record,
								t_color_3d *attenuation,
								t_ray *scattered_ray)
{
	const t_hit_record	*record = void_record;
	const t_material	*material = record->material;
	t_vector_3d			direction;
	const double		refraction_index = material->refraction_index;
	double				refraction_ratio;

	*attenuation = (t_color_3d){0.99, 0.99, 0.99};
	if (record->front_face)
		refraction_ratio = 1.0 / refraction_index;
	else
		refraction_ratio = refraction_index;

	t_vector_3d unit_direction = unit(incident_ray.direction);
	double cos_theta = dot(negative(unit_direction), record->normal);
	cos_theta = ft_min_d(cos_theta, 1.0);
	double sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	double reflectance = schlicks_approximation(cos_theta, refraction_ratio);

	bool cannot_refract = refraction_ratio * sin_theta > 1.0;
	bool random_reflection = reflectance > random_double();
	if (cannot_refract || random_reflection)
		direction = reflect(unit_direction, record->normal);
	else
		direction = refract(unit_direction, record->normal, refraction_ratio);

	*scattered_ray = (t_ray){record->intersection, direction};
	return true;
}
