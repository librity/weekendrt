/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 18:54:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_sphere	*new_sphere(t_point_3d center, double radius, t_material *material)
{
	t_sphere *new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	if (new == NULL)
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->material = material;
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
	record->material = sphere->material;

	return (true);
}

t_color_3d		render_matte_sphere(t_hit_record record,
										t_list *spheres,
										int depth)
{
	t_point_3d target = add(record.intersection, random_in_hemisphere(record.normal));
	t_ray diffuse_ray = (t_ray){record.intersection, sub(target, record.intersection)};
	t_color_3d shade = cast_ray(diffuse_ray, spheres, depth - 1);
	shade = scalar_times(0.5, shade);
	return (shade);
}

t_color_3d		render_sphere(t_ray ray,
								t_hit_record *record,
								t_list *spheres,
								int depth)
{
	t_ray				scattered;
	t_color_3d			attenuation;
	t_material			*material = record->material;
	t_scatter_callback	scattered_ray = material->scattered;

	if (scattered_ray(&ray, record, &attenuation, &scattered, material))
	{
		t_color_3d material_color = cast_ray(scattered, spheres, depth - 1);
		t_color_3d attenuated = product(attenuation, material_color);
		return (attenuated);
	}
	return ((t_color_3d){0.0, 0.0, 0.0});
}