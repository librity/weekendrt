/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 22:01:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	initialize_camera(t_camera *camera,
							double aspect_ratio,
							double vertical_fov_degrees)
{
	double vertical_fov_radians = degrees_to_radians(vertical_fov_degrees);
	double height = tan(vertical_fov_radians / 2);
	double viewport_height = 2.0 * height;
	double viewport_width = aspect_ratio * viewport_height;

	double focal_length = 1.0;

	camera->origin = (t_point_3d){0.0, 0.0, 0.0};
	camera->horizontal = (t_vector_3d){viewport_width, 0.0, 0.0};
	camera->vertical = (t_vector_3d){0.0, viewport_height, 0.0};

	t_point_3d lower_left_corner;
	lower_left_corner = sub(camera->origin, scalar_div(2.0, camera->horizontal));
	lower_left_corner = sub(lower_left_corner, scalar_div(2.0, camera->vertical));
	lower_left_corner = sub(lower_left_corner, (t_vector_3d){0.0, 0.0, focal_length});
	camera->lower_left_corner = lower_left_corner;
}
