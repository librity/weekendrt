/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 18:21:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

typedef struct	s_sphere_params
{
	t_list		**materials;
	t_list		**spheres;

	t_point_3d	center;
	double		radius;

	t_color_3d	albedo;
	double		fuzziness;
	double		refraction_index;
}				t_sphere_params;

void			create_matte_sphere(t_sphere_params p);
void			add_sphere(t_sphere_params p, t_material *material);
void			add_matte_sphere(t_sphere_params p);
void			add_metallic_sphere(t_sphere_params p);
void			add_dielectric_sphere(t_sphere_params p);

#endif
