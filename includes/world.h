/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 01:42:40 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

void	create_matte_sphere(t_list **materials,
								t_list **spheres,
								t_point_3d center,
								double radius,
								t_color_3d albedo);
void	add_sphere(t_list **spheres,
					t_point_3d center,
					double radius,
					t_material *material);
void	add_matte_sphere(t_list **materials,
							t_list **spheres,
							t_point_3d center,
							double radius,
							t_color_3d albedo);
void	add_metallic_sphere(t_list **materials,
							t_list **spheres,
							t_point_3d center,
							double radius,
							t_color_3d albedo,
							double fuzziness);
void	add_dielectric_sphere(t_list **materials,
								t_list **spheres,
								t_point_3d center,
								double radius,
								double refraction_index);

#endif
