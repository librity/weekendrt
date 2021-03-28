/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 02:54:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

bool			ray_hits_sphere(const t_ray ray,
								const t_sphere sphere,
								t_hit_record *record,
								double t_min,
								double t_max)
{
	const t_vector_3d center_to_origin = sub(ray.origin, sphere.center);
	const double a = length_squared(ray.direction);
	const double half_b = dot(center_to_origin, ray.direction);
	const double c = length_squared(center_to_origin) - sphere.radius * sphere.radius;
	const double discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (false);

	const double dsqrt = sqrt(discriminant);
	double root = (-half_b - dsqrt) / a;

	if (root < t_min || t_max < root) {
		root = (-half_b + dsqrt) / a;
		if (root < t_min || t_max < root)
			return (false);
	}

	record->translation = root;
	record->intersection = ray_at_t(record->translation, ray);
	t_vector_3d outward_normal = sub(record->intersection, sphere.center);
	outward_normal = scalar_div(sphere.radius, record->normal);
	set_face_normal(ray, outward_normal, record);

	return (true);
}

t_color_3i		render_sphere_surface(const t_ray ray, double translation)
{
	t_vector_3d translated_ray = ray_at_t(translation, ray);
	t_vector_3d normal = sub(translated_ray, (t_vector_3d){0.0, 0.0, -1.0});
	normal = unit(normal);
	t_color_3d shade = {normal.x + 1.0, normal.y + 1.0, normal.z + 1.0};
	shade = scalar_times(0.5, shade);
	return (color_3d_to_i3(shade));
}
