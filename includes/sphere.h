/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 13:10:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include <material.h>

typedef struct	s_sphere
{
	t_point_3d	center;
	double		radius;
	t_material	*material;
}				t_sphere;

t_sphere		*new_sphere(t_point_3d center,
							double radius,
							t_material *material);
void			free_spheres(t_list **spheres);
t_color_3d		render_sphere(t_ray ray,
								t_hit_record *record,
								t_list *spheres,
								int depth);

#endif
