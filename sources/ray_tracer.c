/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 22:18:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	generate_image(t_bitmap_image *image,
						const t_ray_tracer rt,
						const t_camera camera)
{
	t_ray ray;
	t_color_3i color;
	int row;
	int column;

	ray.origin = camera.origin;
	row = rt.height - 1;
	while (row >= 0)
	{
		printf("⌛");
		column = 0;
		while (column < rt.width)
		{
			ray.direction = point_ray(rt, camera, row, column);
			color = cast_ray(ray);
			set_image_pixel(image, color, row, column);
			column++;
		}
		row--;
	}
}
