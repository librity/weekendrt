/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 02:52:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
#define HITTABLE_H

#include <vector_3d.h>
#include <ray.h>

typedef struct	s_hit_record
{
	t_point_3d	intersection;
	t_vector_3d	normal;
	double		translation;
	bool		front_face;
}				t_hit_record;

void			set_face_normal(const t_ray ray,
								const t_vector_3d outward_normal,
								t_hit_record *record);

#endif