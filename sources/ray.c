/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 19:15:27 by lpaulo-m         ###   ########.fr       */
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
	t_vector_3d direction;

	double horizontal_direction;
	double vertical_direction;

	horizontal_direction = (double)(column) / (rt.width - 1);
	vertical_direction = (double)(row) / (rt.height - 1);

	direction = camera.lower_left_corner;
	direction = add(direction, scalar(horizontal_direction, camera.horizontal));
	direction = add(direction, scalar(vertical_direction, camera.vertical));
	direction = sub(direction, camera.origin);
	return (direction);
}

t_color_3d		cast_ray(t_ray ray)
{
	t_color_3d hue_1 = {1.0, 1.0, 1.0};
	t_color_3d hue_2 = {0.5, 0.7, 1.0};
	t_vector_3d unit_direction;
	double translation;

	unit_direction = unit(ray.direction);
	translation = 0.5 * (unit_direction.y + 1.0);
	hue_1 = scalar(1.0 - translation, hue_1);
	hue_2 = scalar(translation, hue_2);
	return (add(hue_1, hue_2));
}
