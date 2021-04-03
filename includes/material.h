/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:53:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include <hittable.h>

typedef bool	(*t_scatter_callback)(t_ray incident_ray,
										void *void_record,
										t_color_3d *attenuation,
										t_ray *scattered_ray);

typedef struct	s_material
{
	t_color_3d			albedo;
	double				fuzziness;
	double				refraction_index;
	t_scatter_callback	scattered;
}				t_material;

t_material		*prototype_material(t_scatter_callback scattered);
void			free_materials(t_list **materials);

#endif
