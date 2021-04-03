/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 04:26:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_color_3d	color(double red, double green, double blue)
{
	return (color_3d(red, green, blue));
}

t_color_3d	color_3d(double red, double green, double blue)
{
	return ((t_color_3d){red, green, blue});
}

t_color_3i	color_3i(int red, int green, int blue)
{
	return ((t_color_3i){red, green, blue});
}

t_color_3i	color_3d_to_i3(t_color_3d color_3d)
{
	t_color_3i color_3i;

	color_3i.red = (int)(255.999 * color_3d.x);
	color_3i.green = (int)(255.999 * color_3d.y);
	color_3i.blue = (int)(255.999 * color_3d.z);
	return (color_3i);
}
