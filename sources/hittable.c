/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 02:44:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 02:51:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	set_face_normal(const t_ray ray,
						const t_vector_3d outward_normal,
						t_hit_record *record)
{
	record->front_face = dot(ray.direction, outward_normal) < 0;
	record->normal = record->front_face ? outward_normal : negative(outward_normal);
}
