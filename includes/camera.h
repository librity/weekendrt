/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 21:28:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <vector_3d.h>

typedef struct	s_camera
{
	double		aspect_ratio;
	// double		vertical_fov;

	double		viewport_height;
	double		viewport_width;
	double		focal_length;

	t_point_3d	origin;
	t_vector_3d	horizontal;
	t_vector_3d	vertical;
	t_point_3d	lower_left_corner;
}				t_camera;

void			initialize_camera(t_camera *camera, double aspect_ratio);

#endif
