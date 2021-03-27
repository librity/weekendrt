/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weekendrt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 17:53:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEEKENDRT_H
# define WEEKENDRT_H

# include <ft_libbmp.h>
# include <vector_3d.h>
# include <color.h>
# include <ray.h>
# include <errors.h>

typedef struct	s_camera
{
	double		viewport_height;
	double		viewport_width;
	double		focal_length;

	t_point_3d	origin;
	t_vector_3d	horizontal;
	t_vector_3d	vertical;
	t_point_3d	lower_left_corner;
}				t_camera;

typedef struct	s_ray_tracer
{
	char *file_name;

	double aspect_ratio;
	int width;
	int height;

	t_camera camera;
}				t_ray_tracer;

void	initialize_camera(t_ray_tracer *c, t_camera *camera);

#endif
