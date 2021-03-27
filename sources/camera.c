/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 19:09:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	initialize_camera(t_camera *camera, double aspect_ratio)
{
	camera->viewport_height = 2.0;
	camera->viewport_width = aspect_ratio * camera->viewport_height;
	camera->focal_length = 1.0;

	camera->origin = (t_point_3d){0.0, 0.0, 0.0};
	camera->horizontal = (t_vector_3d){camera->viewport_width, 0.0, 0.0};
	camera->vertical = (t_vector_3d){0.0, camera->viewport_height, 0.0};
	camera->lower_left_corner = sub(camera->origin, scalar_div(2.0, camera->horizontal));
	camera->lower_left_corner = sub(camera->lower_left_corner, scalar_div(2.0, camera->vertical));
	camera->lower_left_corner = sub(camera->lower_left_corner, (t_vector_3d){0.0, 0.0, camera->focal_length});
}
