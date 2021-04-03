/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:17:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <vector.h>

typedef struct	s_camera_params
{
	t_point_3d	look_from;
	t_point_3d	look_at;
	t_vector_3d	view_up;

	double		vertical_fov_degrees;
	double		aperture;
	double		focus_distance;
}				t_camera_params;

typedef struct	s_camera
{
	t_vector_3d	basis_u;
	t_vector_3d	basis_v;
	t_vector_3d	basis_w;

	t_point_3d	origin;
	t_vector_3d	horizontal;
	t_vector_3d	vertical;
	t_point_3d	lower_left_corner;

	double		lens_radius;
}				t_camera;

void			initialize_camera(t_camera *camera,
									double aspect_ratio,
									t_camera_params p);

#endif
