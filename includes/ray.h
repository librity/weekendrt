/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 20:06:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <vector_3d.h>
# include <ray_tracer.h>

typedef struct	s_ray
{
	t_point_3d	origin;
	t_vector_3d	direction;
}				t_ray;

t_point_3d		ray_at_t(double translation, t_ray ray);
t_vector_3d		point_ray(const t_ray_tracer rt,
							const t_camera camera,
							int row,
							int column);
t_color_3i		cast_gradient_ray(t_ray ray, t_color_3d	tone);

#endif
