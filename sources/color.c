/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 18:26:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_color_3i	color_3d_to_i3(t_color_3d color_3d)
{
	t_color_3i color_3i;

	color_3i.red = (int)(255.999 * color_3d.x);
	color_3i.green = (int)(255.999 * color_3d.y);
	color_3i.blue = (int)(255.999 * color_3d.z);
	return (color_3i);
}

t_color_3d	ray_color(t_ray ray)
{
	t_color_3d hue_1 = {1.0, 1.0, 1.0};
	t_color_3d hue_2 = {0.5, 0.7, 1.0};
	t_vector_3d unit_direction;
	double translation;

	unit_direction = unit(ray.direction);
	translation = 0.5 * (unit_direction.y + 1.0);
	hue_1 = scalar(1.0 - translation, hue_1);
	hue_2 = scalar(translation, hue_2);
	return (add(hue_1, hue_2));
}
