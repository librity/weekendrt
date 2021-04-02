/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 20:25:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include <vector_3d.h>
# include <camera.h>

typedef struct	s_ray_tracer
{
	char		*file_name;

	double		aspect_ratio;
	int			width;
	int			height;
	int			samples_per_pixel;
	int			max_depth;

	t_camera	camera;

	t_list		*materials;
	t_list		*spheres;
}				t_ray_tracer;

t_color_3i		trace_sample_rays(const t_ray_tracer rt,
									const t_camera camera,
									int row,
									int column);
void			generate_image(t_bitmap_image *image,
								const t_ray_tracer rt,
								const t_camera camera);
void			cleanup_ray_tracer(t_ray_tracer *rt);

#endif
