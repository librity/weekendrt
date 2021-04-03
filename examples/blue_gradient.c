/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_gradient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 15:54:07 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void	generate_blue_gradient(t_bitmap_image *image,
								const t_ray_tracer rt,
								const t_camera camera)
{
	t_ray ray;
	t_color_3d color;
	t_color_3i pixel_color;
	t_color_3d	blue_tone = {0.5, 0.7, 1.0};
	int row;
	int column;

	row = rt.height - 1;
	while (row >= 0)
	{
		ft_putstr("⌛");
		column = 0;
		while (column < rt.width)
		{
			ray = get_ray(rt, camera, row, column);
			color = hit_gradient_background(ray, blue_tone);
			pixel_color = color_3d_to_i3(color);
			set_image_pixel(image, pixel_color, row, column);
			column++;
		}
		row--;
	}
}

static void initialize_ray_tracer(t_ray_tracer *rt, char **arguments)
{
	rt->file_name = arguments[1];

	rt->aspect_ratio = 16.0 / 9.0;
	rt->width = 1920;
	rt->height = (int)(rt->width / rt->aspect_ratio);

	initialize_camera(&(rt->camera), rt->aspect_ratio);
}

int main(int argc, char **argv)
{
	t_ray_tracer rt;
	t_bitmap_image image;

	handle_arguments(argc);
	initialize_ray_tracer(&rt, argv);
	bm_initialize_bitmap(&image, rt.width, rt.height);

	ft_putstr("Scaning lines: ");
	generate_blue_gradient(&image, rt, rt.camera);
	ft_putstr(" Done!\n");

	bm_save_bitmap(&image, rt.file_name);
	bm_free_bitmap(&image);
	return 0;
}
