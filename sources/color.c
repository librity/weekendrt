/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 18:08:23 by lpaulo-m         ###   ########.fr       */
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

t_color_3i sample_pixel_color(t_color_3d sampled_color, int samples_per_pixel)
{
	t_color_3i color_3i;
	const double scale = 1.0 / samples_per_pixel;
	
	sampled_color.x *= scale;
	sampled_color.y *= scale;
	sampled_color.z *= scale;

	color_3i.red = (int)(256 * clamp(sampled_color.x, 0.0, 0.999));
	color_3i.green = (int)(256 * clamp(sampled_color.y, 0.0, 0.999));
	color_3i.blue = (int)(256 * clamp(sampled_color.z, 0.0, 0.999));
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
