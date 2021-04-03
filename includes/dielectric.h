/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 12:30:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIELECTRIC_H
# define DIELECTRIC_H

# include <material.h>

t_material		*make_dielectric(double refraction_index);
bool			scatter_dielectric(t_ray incident_ray,
									void *void_record,
									t_color_3d *attenuation,
									t_ray *scattered_ray);

#endif
