/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:06:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/29 04:28:59 by lpaulo-m         ###   ########.fr       */
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

t_color_3d	scale_and_gamma2_correct(t_color_3d sampled_color, const double scale)
{
	// Divide the color by the number of samples and gamma-correct for gamma=2.0.
	sampled_color = scalar_times(scale, sampled_color);
	sampled_color = vsqrt(sampled_color);
	return (sampled_color);
}

t_color_3i sample_pixel_color(t_color_3d sampled_color, int samples_per_pixel)
{
	t_color_3i color_3i;
	const double scale = 1.0 / samples_per_pixel;

	sampled_color = scale_and_gamma2_correct(sampled_color, scale);

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
