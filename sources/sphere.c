/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 01:46:52 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 12:35:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_sphere	*new_sphere(t_point_3d center, double radius, t_material *material)
{
	t_sphere *new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	if (new == NULL)
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->material = material;
	return (new);
}

void		free_spheres(t_list **spheres)
{
	ft_lstclear(spheres, &free);
}

t_color_3d		render_sphere(t_ray ray,
								t_hit_record *record,
								t_list *spheres,
								int depth)
{
	t_ray				scattered;
	t_color_3d			attenuation;
	t_scatter_callback	scatteres_ray = record->material->scattered;

	if (scatteres_ray(ray, record, &attenuation, &scattered))
	{
		t_color_3d scattered_color = cast_ray(scattered, spheres, depth - 1);
		t_color_3d attenuated = product(attenuation, scattered_color);
		return (attenuated);
	}
	return ((t_color_3d){0.0, 0.0, 0.0});
}