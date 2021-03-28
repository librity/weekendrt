/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 17:12:07 by lpaulo-m         ###   ########.fr       */
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

	t_camera	camera;
	t_list		*spheres;
}				t_ray_tracer;

void			generate_image(t_bitmap_image *image,
								const t_ray_tracer rt,
								const t_camera camera);

#endif
