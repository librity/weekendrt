/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:50:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 12:31:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METALLIC_H
# define METALLIC_H

# include <material.h>

t_material		*make_metallic(t_color_3d albedo, double fuzziness);
bool			scatter_metallic(t_ray incident_ray,
									void *void_record,
									t_color_3d *attenuation,
									t_ray *scattered_ray);

#endif
