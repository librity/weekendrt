/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_effects.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 23:47:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_EFFECTS_H
# define RAY_EFFECTS_H

# include <ray.h>

t_vector_3d		point_ray(t_camera camera,
							double horizontal,
							double vertical);
t_ray			set_ray(t_camera camera,
						double horizontal,
						double vertical);

t_vector_3d		point_ray_dof(t_camera camera,
								t_vector_3d offset,
								double horizontal,
								double vertical);
t_ray			set_ray_dof(t_camera camera,
							double horizontal,
							double vertical);

#endif
