/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 22:34:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	initialize_camera(t_camera *camera,
							double aspect_ratio,
							t_point_3d look_from,
							t_point_3d look_at,
							t_vector_3d view_up,
							double vertical_fov_degrees)
{
	double vertical_fov_radians = degrees_to_radians(vertical_fov_degrees);
	double height = tan(vertical_fov_radians / 2);
	double viewport_height = 2.0 * height;
	double viewport_width = aspect_ratio * viewport_height;

	t_vector_3d basis_w = unit(sub(look_from, look_at));
	t_vector_3d basis_u = unit(cross(view_up, basis_w));
	t_vector_3d basis_v = cross(basis_w, basis_u);

	camera->origin = look_from;
	camera->horizontal = scalar_times(viewport_width, basis_u);
	camera->vertical = scalar_times(viewport_height, basis_v);

	t_point_3d lower_left_corner;
	lower_left_corner = sub(camera->origin, scalar_div(2.0, camera->horizontal));
	lower_left_corner = sub(lower_left_corner, scalar_div(2.0, camera->vertical));
	lower_left_corner = sub(lower_left_corner, basis_w);
	camera->lower_left_corner = lower_left_corner;
}
