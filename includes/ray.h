/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:24:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <ray_tracer.h>

typedef struct	s_ray
{
	t_point_3d	origin;
	t_vector_3d	direction;
}				t_ray;

t_ray			ray(t_point_3d	origin, t_vector_3d	direction);
t_point_3d		ray_at_t(double translation, t_ray ray);
t_ray			get_ray(const t_ray_tracer rt,
						const t_camera camera,
						int row,
						int column);
t_ray			get_sample_ray(const t_ray_tracer rt,
						const t_camera camera,
						int row,
						int column);

#endif
