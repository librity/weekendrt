/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 19:00:41 by lpaulo-m         ###   ########.fr       */
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

void		set_image_pixel(t_bitmap_image *image,
							t_color_3i color,
							int row,
							int column)
{
	t_bitmap_pixel *target_pixel;

	target_pixel = &image->pixels[row][column];
	ft_set_pixel(target_pixel, color.red, color.green, color.blue);
}
