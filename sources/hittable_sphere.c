/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 13:09:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

// bool	vectorial_quadratic(const t_ray ray,
// 								const t_sphere *sphere,
// 								double min_translation,
// 								double max_translation)
// {
// 	const t_vector_3d center_to_origin = sub(ray.origin, sphere->center);
// 	const double a = length_squared(ray.direction);
// 	const double half_b = dot(center_to_origin, ray.direction);
// 	const double c = length_squared(center_to_origin) - sphere->radius * sphere->radius;
// 	const double discriminant = half_b * half_b - a * c;

// 	if (discriminant < 0)
// 		return (false);

// 	const double dsqrt = sqrt(discriminant);
// 	double root = (-half_b - dsqrt) / a;

// 	if (root < min_translation || max_translation < root)
// 	{
// 		root = (-half_b + dsqrt) / a;
// 		if (root < min_translation || max_translation < root)
// 			return (false);
// 	}
// 	return (true);
// }

bool			ray_hits_sphere(const t_ray ray,
								const t_sphere *sphere,
								t_hit_record *record,
								double t_min,
								double t_max)
{
	const t_vector_3d center_to_origin = sub(ray.origin, sphere->center);
	const double a = length_squared(ray.direction);
	const double half_b = dot(center_to_origin, ray.direction);
	const double c = length_squared(center_to_origin) - sphere->radius * sphere->radius;
	const double discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (false);

	const double dsqrt = sqrt(discriminant);
	double root = (-half_b - dsqrt) / a;

	if (root < t_min || t_max < root)
	{
		root = (-half_b + dsqrt) / a;
		if (root < t_min || t_max < root)
			return (false);
	}

	record->translation = root;
	record->intersection = ray_at_t(record->translation, ray);
	t_vector_3d outward_normal = sub(record->intersection, sphere->center);
	outward_normal = scalar_div(sphere->radius, outward_normal);
	set_face_normal(ray, outward_normal, record);
	record->material = sphere->material;

	return (true);
}
