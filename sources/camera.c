/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 04:15:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void	set_orthonormal_basis(t_camera *camera, t_camera_params p)
{
	camera->basis_w = unit(sub(p.look_from, p.look_at));
	camera->basis_u = unit(cross(p.view_up, camera->basis_w));
	camera->basis_v = cross(camera->basis_w, camera->basis_u);
}

static void	set_position(t_camera *camera,
						t_camera_params p,
						double viewport_width,
						double viewport_height)
{
	camera->origin = p.look_from;
	camera->horizontal = scalar_times(p.focus_distance * viewport_width,
										camera->basis_u);
	camera->vertical = scalar_times(p.focus_distance * viewport_height,
										camera->basis_v);
}

static void	set_lower_left_corner(t_camera *camera, t_camera_params p)
{
	t_point_3d lower_left_corner;

	lower_left_corner = sub(camera->origin,
							scalar_div(2.0, camera->horizontal));
	lower_left_corner = sub(lower_left_corner,
							scalar_div(2.0, camera->vertical));
	lower_left_corner = sub(lower_left_corner,
							scalar_times(p.focus_distance, camera->basis_w));
	camera->lower_left_corner = lower_left_corner;
}

void		initialize_camera(t_camera *camera,
								double aspect_ratio,
								t_camera_params p)
{
	double height;
	double viewport_height;
	double viewport_width;

	height = degrees_to_radians(p.vertical_fov_degrees);
	height = tan(height / 2);
	viewport_height = 2.0 * height;
	viewport_width = aspect_ratio * viewport_height;
	set_orthonormal_basis(camera, p);
	set_position(camera, p,  viewport_width, viewport_height);
	set_lower_left_corner(camera, p);
	camera->lens_radius = p.aperture / 2.0;
}
