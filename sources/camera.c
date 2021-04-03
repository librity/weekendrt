/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 23:49:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	initialize_camera(t_camera *camera,
							double aspect_ratio,
							t_camera_params p)
{
	double vertical_fov_radians = degrees_to_radians(p.vertical_fov_degrees);
	double height = tan(vertical_fov_radians / 2);
	double viewport_height = 2.0 * height;
	double viewport_width = aspect_ratio * viewport_height;

	camera->basis_w = unit(sub(p.look_from, p.look_at));
	camera->basis_u = unit(cross(p.view_up, camera->basis_w));
	camera->basis_v = cross(camera->basis_w, camera->basis_u);

	camera->origin = p.look_from;
	camera->horizontal = scalar_times(p.focus_distance * viewport_width,
										camera->basis_u);
	camera->vertical = scalar_times(p.focus_distance * viewport_height,
										camera->basis_v);

	t_point_3d lower_left_corner;
	lower_left_corner = sub(camera->origin,
							scalar_div(2.0, camera->horizontal));
	lower_left_corner = sub(lower_left_corner,
							scalar_div(2.0, camera->vertical));
	lower_left_corner = sub(lower_left_corner,
							scalar_times(p.focus_distance, camera->basis_w));
	camera->lower_left_corner = lower_left_corner;

	camera->lens_radius = p.aperture / 2.0;
}
