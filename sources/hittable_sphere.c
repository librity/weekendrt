/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 14:23:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static bool	vectorial_quadratic(const t_ray ray,
								const t_sphere *sphere,
								double min_translation,
								double max_translation,
								double *root)
{
	const t_vector_3d center_to_origin = sub(ray.origin, sphere->center);
	t_quadratic_result r;

	r.a = length_squared(ray.direction);
	r.half_b = dot(center_to_origin, ray.direction);
	r.c = length_squared(center_to_origin) - sphere->radius * sphere->radius;
	return (quadratic(r, min_translation, max_translation, root));
}

bool		ray_hits_sphere(const t_ray ray,
							const t_sphere *sphere,
							t_hit_record *record,
							double t_min,
							double t_max)
{
	t_vector_3d	outward_normal;
	double		root;
	bool		has_real_roots;

	has_real_roots = vectorial_quadratic(ray, sphere, t_min, t_max, &root);
	if (unless(has_real_roots))
		return (false);
	record->translation = root;
	record->intersection = ray_at_t(record->translation, ray);
	outward_normal = sub(record->intersection, sphere->center);
	outward_normal = scalar_div(sphere->radius, outward_normal);
	set_face_normal(ray, outward_normal, record);
	record->material = sphere->material;
	return (true);
}
