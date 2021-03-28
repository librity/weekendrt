/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 18:08:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	generate_image(t_bitmap_image *image,
						const t_ray_tracer rt,
						const t_camera camera)
{
	t_ray		ray;
	t_color_3d	sample_color;
	t_color_3i	pixel_color;
	int			row;
	int			column;
	int			sample;

	row = rt.height - 1;
	while (row >= 0)
	{
		ft_putstr("⌛");
		column = 0;
		while (column < rt.width)
		{
			t_color_3d sample_result = (t_color_3d){0, 0, 0};
			sample = rt.samples_per_pixel;
			while (sample--)
			{
				ray = get_sample_ray(rt, camera, row, column);
				sample_color = cast_ray(ray, rt.spheres);
				sample_result.x += sample_color.x;
				sample_result.y += sample_color.y;
				sample_result.z += sample_color.z;
			}
			pixel_color = sample_pixel_color(sample_result, rt.samples_per_pixel);
			set_image_pixel(image, pixel_color, row, column);
			column++;
		}
		row--;
	}
}
