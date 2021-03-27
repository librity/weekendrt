/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 20:20:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_point_3d		ray_at_t(double translation, t_ray ray)
{
	t_vector_3d reach;

	reach = scalar(translation, ray.direction);
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
	direction = add(direction, scalar(horizontal_direction, camera.horizontal));
	direction = add(direction, scalar(vertical_direction, camera.vertical));
	direction = sub(direction, camera.origin);
	return (direction);
}

t_color_3i		cast_gradient_ray(t_ray ray, t_color_3d	tone)
{
	t_color_3d	base = {1.0, 1.0, 1.0};
	t_color_3d	cast;
	t_vector_3d	unit_direction;
	double		gradient;

	unit_direction = unit(ray.direction);
	gradient = 0.5 * (unit_direction.y + 1.0);
	base = scalar(1.0 - gradient, base);
	tone = scalar(gradient, tone);
	cast = add(base, tone);
	return (color_3d_to_i3(cast));
}
