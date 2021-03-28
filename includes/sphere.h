/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 17:49:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include <vector_3d.h>
# include <ray.h>
# include <color.h>
# include <hittable.h>

typedef struct	s_sphere
{
	t_point_3d	center;
	double		radius;
}				t_sphere;

t_sphere		*new_sphere(t_point_3d center, double radius);
void			free_spheres(t_list **spheres);
bool			ray_hits_sphere(const t_ray ray,
								const t_sphere *sphere,
								t_hit_record *record,
								double t_min,
								double t_max);
t_color_3d		render_sphere_surface(t_vector_3d normal);

#endif
