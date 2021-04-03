/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:23:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 17:59:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_material		*make_dielectric(double refraction_index)
{
	t_material *new;

	new = prototype_material(&scatter_dielectric);
	new->refraction_index = refraction_index;
	return (new);
}

static bool		refract_ray(t_vector_3d unit_direction,
							t_vector_3d normal,
							double refraction)
{
	double	cos_theta;
	double	sin_theta;
	double	reflectance;
	bool	cannot_refract;
	bool	random_reflection;

	cos_theta = dot(negative(unit_direction), normal);
	cos_theta = ft_min_d(cos_theta, 1.0);
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	reflectance = schlicks_approximation(cos_theta, refraction);
	cannot_refract = refraction * sin_theta > 1.0;
	random_reflection = reflectance > random_double();
	return (cannot_refract || random_reflection);
}

static double	refraction_ratio(double refraction_index, bool front_face)
{
	if (front_face)
		return (1.0 / refraction_index);
	return (refraction_index);
}

bool			scatter_dielectric(t_ray incident_ray,
									void *void_record,
									t_color_3d *attenuation,
									t_ray *scattered_ray)
{
	const t_hit_record	*record = void_record;
	const t_material	*material = record->material;
	const t_vector_3d	unit_direction = unit(incident_ray.direction);
	t_vector_3d			direction;
	double				refraction;

	*attenuation = color(0.99, 0.99, 0.99);
	refraction = refraction_ratio(material->refraction_index,
									record->front_face);
	if (refract_ray(unit_direction, record->normal, refraction))
		direction = reflect(unit_direction, record->normal);
	else
		direction = refract(unit_direction, record->normal, refraction);
	*scattered_ray = ray(record->intersection, direction);
	return (true);
}
