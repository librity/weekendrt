/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 18:52:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

#include "color.h"
#include "ray.h"
#include "hittable.h"

typedef bool (*t_scatter_callback)(t_ray *incident_ray,
									void *void_record,
									t_color_3d *attenuation,
									t_ray *scattered_ray,
									void *void_material);

typedef struct	s_material
{
	t_color_3d			albedo;
	double				fuzziness;
	t_scatter_callback	scattered;
}				t_material;

t_material	*new_material(t_color_3d albedo, t_scatter_callback scattered);
t_material	*make_lambertian(t_color_3d albedo);
t_material	*make_metallic(t_color_3d albedo, double fuzziness);
bool		scattered_lambertian(t_ray *incident_ray,
									void *void_record,
									t_color_3d *attenuation,
									t_ray *scattered_ray,
									void *void_material);
bool		scattered_metal(t_ray *incident_ray,
							void *void_record,
							t_color_3d *attenuation,
							t_ray *scattered_ray,
							void *void_material);

#endif
