/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:51:38 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 13:21:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

clock_t 	log_start(t_ray_tracer rt)
{
	clock_t timer;

	ft_putstr("\nMaterials: ");
	ft_putnbr(ft_lstsize(rt.materials));
	ft_putstr("\nSpheres: ");
	ft_putnbr(ft_lstsize(rt.spheres));
	ft_putstr("\nScaning lines: ");
	timer = clock();
	return (timer);
}

clock_t		log_end(clock_t timer)
{
	double elapsed_time;

	timer = clock() - timer;
	elapsed_time = ((double)timer) / CLOCKS_PER_SEC;
	ft_putstr(" Done!");
	ft_putstr("\nElapsed time: ");
	ft_putnbr((int)elapsed_time);
	ft_putstr(" seconds\n\n");
	return (timer);
}

t_color_3i	trace_sample_rays(const t_ray_tracer rt,
								const t_camera camera,
								int row,
								int column)
{
	t_ray		ray;
	t_color_3d	sample_result;
	t_color_3d	sample_color;
	t_color_3i	pixel_color;
	int			samples;

	sample_result = (t_color_3d){0, 0, 0};
	samples = rt.samples_per_pixel;
	while (samples--)
	{
		ray = get_sample_ray(rt, camera, row, column);
		sample_color = cast_ray(ray, rt.spheres, rt.max_depth);
		sample_result = add(sample_result, sample_color);
	}
	pixel_color = sample_pixel_color(sample_result, rt.samples_per_pixel);
	return (pixel_color);
}

void		generate_image(t_bitmap_image *image,
							const t_ray_tracer rt,
							const t_camera camera)
{
	t_color_3i	pixel_color;
	int			row;
	int			column;

	row = rt.height - 1;
	while (row >= 0)
	{
		ft_putstr("⌛");
		column = 0;
		while (column < rt.width)
		{
			pixel_color = trace_sample_rays(rt, camera, row, column);
			set_image_pixel(image, pixel_color, row, column);
			column++;
		}
		row--;
	}
}

void		cleanup_ray_tracer(t_ray_tracer *rt)
{
	free_spheres(&(rt->spheres));
	free_materials(&(rt->materials));
}
