/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_effects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:49:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 04:23:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_vector_3d		point_ray(t_camera camera,
							double horizontal,
							double vertical)
{
	t_vector_3d	direction;

	direction = camera.lower_left_corner;
	direction = add(direction, scalar_times(horizontal, camera.horizontal));
	direction = add(direction, scalar_times(vertical, camera.vertical));
	direction = sub(direction, camera.origin);
	return (direction);
}

t_ray			set_ray(t_camera camera,
						double horizontal,
						double vertical)
{
	t_ray	ray;

	ray.origin = camera.origin;
	ray.direction = point_ray(camera, horizontal, vertical);
	return (ray);
}

t_vector_3d		point_ray_dof(t_camera camera,
								t_vector_3d offset,
								double horizontal,
								double vertical)
{
	t_vector_3d	direction;

	direction = point_ray(camera, horizontal, vertical);
	direction = sub(direction, offset);
	return (direction);
}

t_ray			set_ray_dof(t_camera camera,
							double horizontal,
							double vertical)
{
	t_ray	ray;
	t_vector_3d offset;

	offset = scalar_times(camera.lens_radius, random_in_unit_disk());
	offset = add(
		scalar_times(offset.x, camera.basis_u),
		scalar_times(offset.y, camera.basis_v)
	);
	ray.origin = add(camera.origin, offset);
	ray.direction = point_ray_dof(camera, offset, horizontal, vertical);
	return (ray);
}
