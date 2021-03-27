/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 18:29:39 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>
#include <stdio.h>

static void set_pixels(t_bitmap_image *image, t_ray_tracer c)
{
	t_ray ray;
	const t_camera camera = c.camera;

	t_color_3d color_3d;
	t_color_3i color;

	int row;
	int column;

	double unit_horizontal;
	double unit_vertical;

	row = c.height - 1;
	while (row >= 0)
	{
		printf("▒");

		column = 0;
		while (column < c.width)
		{
			unit_horizontal = (double)(column) / (c.width - 1);
			unit_vertical = (double)(row) / (c.height - 1);

			ray.origin = camera.origin;

			ray.direction = camera.lower_left_corner;
			ray.direction = add(ray.direction, scalar(unit_horizontal, camera.horizontal));
			ray.direction = add(ray.direction, scalar(unit_vertical, camera.vertical));
			ray.direction = sub(ray.direction, camera.origin);

			color_3d = ray_color(ray);
			color = color_3d_to_i3(color_3d);

			ft_set_pixel(&image->pixels[row][column], color.red, color.green, color.blue);

			column++;
		}
		row--;
	}
}

static void initialize_control(t_ray_tracer *c, char **arguments)
{
	c->file_name = arguments[1];

	c->aspect_ratio = 16.0 / 9.0;
	c->width = 1920;
	c->height = (int)(c->width / c->aspect_ratio);

	initialize_camera(c, &(c->camera));
}

int main(int argc, char **argv)
{
	t_ray_tracer c;
	t_bitmap_image image;

	handle_arguments(argc);
	initialize_control(&c, argv);
	ft_initialize_bitmap(&image, c.width, c.height);

	printf("Scaning lines: ");
	set_pixels(&image, c);
	printf("\nDone.\n");

	ft_save_bitmap(&image, c.file_name);
	ft_free_bitmap(&image);
	return 0;
}
