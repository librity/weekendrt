/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:35:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 18:37:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static bool	vectorial_quadratic(t_vectorial_quadratic_params p)
{
	const t_vector_3d	center_to_origin = sub(p.ray.origin, p.sphere->center);
	t_quadratic_result	r;

	r.a = length_squared(p.ray.direction);
	r.half_b = dot(center_to_origin, p.ray.direction);
	r.c = length_squared(center_to_origin);
	r.c = r.c - p.sphere->radius * p.sphere->radius;
	return (quadratic(r, p.min_translation, p.max_translation, p.root));
}

bool		ray_hits_sphere(t_ray_hits_sphere_params p)
{
	t_vector_3d	outward_normal;
	double		root;
	bool		has_real_roots;

	has_real_roots = vectorial_quadratic((t_vectorial_quadratic_params){
		p.ray, p.sphere, p.t_min, p.t_max, &root
	});
	if (unless(has_real_roots))
		return (false);
	p.record->translation = root;
	p.record->intersection = ray_at_t(p.record->translation, p.ray);
	outward_normal = sub(p.record->intersection, p.sphere->center);
	outward_normal = scalar_div(p.sphere->radius, outward_normal);
	set_face_normal(p.ray, outward_normal, p.record);
	p.record->material = p.sphere->material;
	return (true);
}
