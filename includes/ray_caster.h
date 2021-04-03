/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 04:25:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTER_H
# define RAY_CASTER_H

# include <ray.h>

t_color_3d		hit_gradient_background(const t_ray ray,
										t_color_3d background_tone);
t_color_3d		hit_gradient_background(const t_ray ray,
										t_color_3d background_tone);
t_color_3d		cast_ray(const t_ray ray, t_list *spheres, int depth);

#endif
