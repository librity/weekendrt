/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 01:48:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

double			intersect_sphere(const t_ray ray,
									t_point_3d center,
									double radius)
{
	t_vector_3d center_to_origin = sub(ray.origin, center);
	double a = dot(ray.direction, ray.direction);
	double b = 2.0 * dot(center_to_origin, ray.direction);
	double c = dot(center_to_origin, center_to_origin) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_color_3i		handle_sphere_surface_normal(const t_ray ray,
												double translation)
{
	t_vector_3d translated_ray = ray_at_t(translation, ray);
	t_vector_3d normal = sub(translated_ray, (t_vector_3d){0.0, 0.0, -1.0});
	normal = unit(normal);
	t_color_3d shade = {normal.x + 1.0, normal.y + 1.0, normal.z + 1.0};
	shade = scalar_times(0.5, shade);
	return (color_3d_to_i3(shade));
}
