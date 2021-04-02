/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 19:57:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_material	*new_material(t_color_3d albedo, t_scatter_callback scattered)
{
	t_material *new;

	new = (t_material *)malloc(sizeof(t_material));
	if (new == NULL)
		return (NULL);
	new->albedo = albedo;
	new->scattered = scattered;
	return (new);
}

t_material	*make_lambertian(t_color_3d albedo)
{
	return (new_material(albedo, &scatter_matte));
}

t_material	*make_metallic(t_color_3d albedo, double fuzziness)
{
	t_material *new;

	new = new_material(albedo, &scatter_metal);
	if (fuzziness < 1.0)
		new->fuzziness = fuzziness;
	else
		new->fuzziness = 1.0;
	return (new);
}

bool		scatter_matte(t_ray incident_ray,
									void *void_record,
									t_color_3d *attenuation,
									t_ray *scattered_ray)
{
	(void)incident_ray;
	t_hit_record *record = void_record;
	t_material *material = record->material;

	t_vector_3d scatter_direction = add(record->normal, random_unit_vector());
	if (near_zero(scatter_direction))
		scatter_direction = record->normal;
	*scattered_ray = (t_ray){record->intersection, scatter_direction};
	*attenuation = material->albedo;
	return true;
}

bool		scatter_metal(t_ray incident_ray,
							void *void_record,
							t_color_3d *attenuation,
							t_ray *scattered_ray)
{
	t_hit_record *record = void_record;
	t_material *material = record->material;

	t_vector_3d incident = unit(incident_ray.direction);
	t_vector_3d reflected = reflect(incident, record->normal);
	t_vector_3d fuzz = scalar_times(material->fuzziness, random_in_unit_sphere());
	t_vector_3d fuzzed_reflected = add(reflected, fuzz);

	*scattered_ray = (t_ray){record->intersection, fuzzed_reflected};
	*attenuation = material->albedo;
	return (dot(scattered_ray->direction, record->normal) > 0);
}
