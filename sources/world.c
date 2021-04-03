/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 01:08:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 02:18:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	create_matte_sphere(t_list **materials,
									t_list **spheres,
									t_point_3d center,
									double radius,
									t_color_3d albedo)
{
	t_material *material;
	t_sphere *sphere;

	material = make_matte(albedo);
	*materials = ft_lstnew(material);
	sphere = new_sphere(center, radius, material);
	*spheres = ft_lstnew(sphere);
}

void	add_sphere(t_list **spheres,
					t_point_3d center,
					double radius,
					t_material *material)
{
	t_sphere *sphere;

	sphere = new_sphere(center, radius, material);
	ft_lstadd_back(spheres, ft_lstnew(sphere));
}

void	add_matte_sphere(t_list **materials,
							t_list **spheres,
							t_point_3d center,
							double radius,
							t_color_3d albedo)
{
	t_material *material;

	material = make_matte(albedo);
	ft_lstadd_back(materials, ft_lstnew(material));
	add_sphere(spheres, center, radius, material);
}

void	add_metallic_sphere(t_list **materials,
							t_list **spheres,
							t_point_3d center,
							double radius,
							t_color_3d albedo,
							double fuzziness)
{
	t_material *material;

	material = make_metallic(albedo, fuzziness);
	ft_lstadd_back(materials, ft_lstnew(material));
	add_sphere(spheres, center, radius, material);
}

void	add_dielectric_sphere(t_list **materials,
								t_list **spheres,
								t_point_3d center,
								double radius,
								double refraction_index)
{
	t_material *material;

	material = make_dielectric(refraction_index);
	ft_lstadd_back(materials, ft_lstnew(material));
	add_sphere(spheres, center, radius, material);
}