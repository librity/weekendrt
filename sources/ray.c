/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:24:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_ray		ray(t_point_3d	origin, t_vector_3d	direction)
{
	t_ray new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}

t_point_3d	ray_at_t(double translation, t_ray ray)
{
	t_vector_3d reach;

	reach = scalar_times(translation, ray.direction);
	return (add(ray.origin, reach));
}

t_ray		get_ray(const t_ray_tracer rt,
					const t_camera camera,
					int row,
					int column)
{
	double	horizontal_direction;
	double	vertical_direction;

	horizontal_direction = (double)(column) / (rt.width - 1);
	vertical_direction = (double)(row) / (rt.height - 1);
	return (set_ray_dof(camera, horizontal_direction, vertical_direction));
}

t_ray		get_sample_ray(const t_ray_tracer rt,
							const t_camera camera,
							int row,
							int column)
{
	double	horizontal_direction;
	double	vertical_direction;

	horizontal_direction = (double)(column - random_double()) / (rt.width - 1);
	vertical_direction = (double)(row - random_double()) / (rt.height - 1);
	return (set_ray_dof(camera, horizontal_direction, vertical_direction));
}
