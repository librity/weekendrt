/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matte.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 12:31:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATTE_H
# define MATTE_H

# include <material.h>

t_material		*make_matte(t_color_3d albedo);
bool			scatter_matte(t_ray incident_ray,
								void *void_record,
								t_color_3d *attenuation,
								t_ray *scattered_ray);

#endif
