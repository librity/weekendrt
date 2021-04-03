/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 13:22:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include <material.h>

typedef struct	s_hit_record
{
	t_point_3d	intersection;
	t_vector_3d	normal;
	t_material	*material;
	double		translation;
	bool		front_face;
}				t_hit_record;

void			set_record(t_hit_record *target, t_hit_record record);
void			set_face_normal(const t_ray ray,
								const t_vector_3d outward_normal,
								t_hit_record *record);

#endif
