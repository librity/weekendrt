/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/29 04:25:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_sphere	*new_sphere(t_point_3d center, double radius)
{
	t_sphere *new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	if (new == NULL)
		return (NULL);
	new->center = center;
	new->radius = radius;
	return (new);
}

void		free_spheres(t_list **spheres)
{
	ft_lstclear(spheres, &free);
}

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
	// outward_normal = unit(outward_normal);
	set_face_normal(ray, outward_normal, record);

	return (true);
}

t_color_3d		render_matte_sphere(t_hit_record record,
										t_list *spheres,
										int depth)
{
	t_point_3d target = add(record.intersection, record.normal);
	target = add(target, random_point_in_unit_sphere());
	t_ray diffuse_ray = (t_ray){record.intersection, sub(target, record.intersection)};
	t_color_3d shade = cast_ray(diffuse_ray, spheres, depth - 1);
	shade = scalar_times(0.5, shade);
	return (shade);
}
