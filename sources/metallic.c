/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:23:59 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:25:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_material	*make_metallic(t_color_3d albedo, double fuzziness)
{
	t_material *new;

	new = prototype_material(&scatter_metallic);
	new->albedo = albedo;
	if (fuzziness < 1.0)
		new->fuzziness = fuzziness;
	else
		new->fuzziness = 1.0;
	return (new);
}

bool		scatter_metallic(t_ray incident_ray,
							void *void_record,
							t_color_3d *attenuation,
							t_ray *scattered_ray)
{
	const t_hit_record	*record = void_record;
	const t_material	*material = record->material;

	t_vector_3d incident = unit(incident_ray.direction);
	t_vector_3d reflected = reflect(incident, record->normal);
	t_vector_3d fuzz = scalar_times(material->fuzziness, random_in_unit_sphere());
	t_vector_3d fuzzed_reflected = add(reflected, fuzz);

	*scattered_ray = ray(record->intersection, fuzzed_reflected);
	*attenuation = material->albedo;
	return (dot(scattered_ray->direction, record->normal) > 0);
}
