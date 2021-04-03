/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 01:08:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 18:18:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	create_matte_sphere(t_sphere_params p)
{
	t_material	*material;
	t_sphere	*sphere;

	material = make_matte(p.albedo);
	*(p.materials) = ft_lstnew(material);
	sphere = new_sphere(p.center, p.radius, material);
	*(p.spheres) = ft_lstnew(sphere);
}

void	add_sphere(t_sphere_params p, t_material *material)
{
	t_sphere *sphere;

	sphere = new_sphere(p.center, p.radius, material);
	ft_lstadd_back(p.spheres, ft_lstnew(sphere));
}

void	add_matte_sphere(t_sphere_params p)
{
	t_material *material;

	material = make_matte(p.albedo);
	ft_lstadd_back(p.materials, ft_lstnew(material));
	add_sphere(p, material);
}

void	add_metallic_sphere(t_sphere_params p)
{
	t_material *material;

	material = make_metallic(p.albedo, p.fuzziness);
	ft_lstadd_back(p.materials, ft_lstnew(material));
	add_sphere(p, material);
}

void	add_dielectric_sphere(t_sphere_params p)
{
	t_material *material;

	material = make_dielectric(p.refraction_index);
	ft_lstadd_back(p.materials, ft_lstnew(material));
	add_sphere(p, material);
}
