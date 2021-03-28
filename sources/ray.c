/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 22:16:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_point_3d		ray_at_t(double translation, t_ray ray)
{
	t_vector_3d reach;

	reach = scalar_times(translation, ray.direction);
	return (add(ray.origin, reach));
}

t_vector_3d		point_ray(const t_ray_tracer rt,
							const t_camera camera,
							int row,
							int column)
{
	t_vector_3d	direction;
	double		horizontal_direction;
	double		vertical_direction;

	horizontal_direction = (double)(column) / (rt.width - 1);
	vertical_direction = (double)(row) / (rt.height - 1);
	direction = camera.lower_left_corner;
	direction = add(direction, scalar_times(horizontal_direction, camera.horizontal));
	direction = add(direction, scalar_times(vertical_direction, camera.vertical));
	direction = sub(direction, camera.origin);
	return (direction);
}

t_color_3i		hit_gradient_background(const t_ray ray,
										t_color_3d background_tone)
{
	t_color_3d	base = {1.0, 1.0, 1.0};
	t_color_3d	cast;
	t_vector_3d	unit_direction;
	double		gradient;

	unit_direction = unit(ray.direction);
	gradient = 0.5 * (unit_direction.y + 1.0);
	base = scalar_times(1.0 - gradient, base);
	background_tone = scalar_times(gradient, background_tone);
	cast = add(base, background_tone);
	return (color_3d_to_i3(cast));
}

double			calculate_discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

bool			ray_hits_sphere(const t_ray ray,
								t_point_3d center,
								double radius)
{
	t_vector_3d oc = sub(ray.origin, center);
	double a = dot(ray.direction, ray.direction);
	double b = 2.0 * dot(oc, ray.direction);
	double c = dot(oc, oc) - radius * radius;
	double discriminant = calculate_discriminant(a, b, c);
	return (discriminant > 0);
}

t_color_3i		cast_ray(const t_ray ray)
{
	if (ray_hits_sphere(ray, (t_point_3d){0, 0, -1}, 0.5))
		return ((t_color_3i){255, 0, 0});
	return (hit_gradient_background(ray, (t_color_3d){0.5, 0.7, 1.0}));
}
