/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 21:34:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_material	*prototype_material(t_scatter_callback scattered)
{
	t_material *new;

	new = (t_material *)malloc(sizeof(t_material));
	if (new == NULL)
		return (NULL);
	new->scattered = scattered;
	return (new);
}

void		free_materials(t_list **materials)
{
	ft_lstclear(materials, &free);
}

t_material	*make_lambertian(t_color_3d albedo)
{
	t_material *new;

	new = prototype_material(&scatter_matte);
	new->albedo = albedo;
	return (new);
}

t_material	*make_metallic(t_color_3d albedo, double fuzziness)
{
	t_material *new;

	new = prototype_material(&scatter_metal);
	new->albedo = albedo;
	if (fuzziness < 1.0)
		new->fuzziness = fuzziness;
	else
		new->fuzziness = 1.0;
	return (new);
}

t_material	*make_dielectric(double refraction_index)
{
	t_material *new;

	new = prototype_material(&scatter_dielectric);
	new->refraction_index = refraction_index;
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

bool		scatter_dielectric(t_ray incident_ray,
								void *void_record,
								t_color_3d *attenuation,
								t_ray *scattered_ray)
{
	t_hit_record *record = void_record;
	t_material *material = record->material;
	t_vector_3d direction;
	double refraction_index = material->refraction_index;
	double refraction_ratio;

	*attenuation = (t_color_3d){0.99, 0.99, 0.99};
	if (record->front_face)
		refraction_ratio = 1.0 / refraction_index;
	else
		refraction_ratio = refraction_index;

	t_vector_3d unit_direction = unit(incident_ray.direction);
	double cos_theta = dot(negative(unit_direction), record->normal);
	cos_theta = smallest_d(cos_theta, 1.0);
	double sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	double reflectance = schlicks_approximation(cos_theta, refraction_ratio);

	bool cannot_refract = refraction_ratio * sin_theta > 1.0;
	bool random_reflection = reflectance > random_double();
	if (cannot_refract || random_reflection)
		direction = reflect(unit_direction, record->normal);
	else
		direction = refract(unit_direction, record->normal, refraction_ratio);

	*scattered_ray = (t_ray){record->intersection, direction};
	return true;
}
