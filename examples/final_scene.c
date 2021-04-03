/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 13:19:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void randomize_world(t_list **materials, t_list **spheres)
{
	t_color_3d albedo;
	double fuzz;
	t_point_3d within_view;
	bool is_within_view;

	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			double randomizer = random_double();
			t_point_3d random_center = point(
				a + 0.9 * random_double(),
				0.2,
				b + 0.9 * random_double());

			within_view = sub(random_center, point(4, 0.2, 0));
			is_within_view = length(within_view) > 0.9;
			if (is_within_view)
			{
				if (randomizer < 0.8)
				{
					albedo = product(rc(), rc());

					add_matte_sphere(materials, spheres, random_center, 0.2,
									 albedo);
					continue;
				}

				if (randomizer < 0.95)
				{
					albedo = rcr(0.5, 1);
					fuzz = random_from(0, 0.5);

					add_metallic_sphere(materials, spheres, random_center, 0.2,
										albedo, fuzz);
					continue;
				}

				add_dielectric_sphere(materials, spheres, random_center, 0.2,
									  1.5);
			}
		}
	}
}

static void initialize_world(t_list **materials, t_list **spheres)
{
	create_matte_sphere(materials, spheres, point(0, -1000, 0), 1000,
						color(0.5, 0.5, 0.5));

	add_matte_sphere(materials, spheres, point(-4, 1, 0), 1.0,
					 color(0.4, 0.2, 0.1));

	add_metallic_sphere(materials, spheres, point(4, 1, 0), 1.0,
						color(0.7, 0.6, 0.5), 0.0);

	add_dielectric_sphere(materials, spheres, point(0, 1, 0), 1.0,
						  1.5);

	randomize_world(materials, spheres);
}

static void configure_camera(t_ray_tracer *rt)
{
	t_camera_params camera_params;

	camera_params.look_from = (t_point_3d){13, 2, 3};
	camera_params.look_at = (t_point_3d){0, 0, 0};
	camera_params.view_up = (t_vector_3d){0, 1, 0};

	camera_params.vertical_fov_degrees = 20.0;
	camera_params.aperture = 0.1;
	camera_params.focus_distance = 10.0;

	initialize_camera(&(rt->camera), rt->aspect_ratio, camera_params);
}

static void initialize_ray_tracer(t_ray_tracer *rt, char **arguments)
{
	rt->file_name = arguments[1];

	rt->aspect_ratio = 16.0 / 9.0;
	// rt->width = 1920;
	rt->width = 400;
	rt->height = (int)(rt->width / rt->aspect_ratio);

	rt->samples_per_pixel = 2;
	// rt->samples_per_pixel = 100;
	// rt->samples_per_pixel = 500;
	rt->max_depth = 2;

	configure_camera(rt);
	initialize_world(&(rt->materials), &(rt->spheres));
}

int main(int argc, char **argv)
{
	t_ray_tracer rt;
	t_bitmap_image image;
	clock_t timer;

	handle_arguments(argc);
	initialize_ray_tracer(&rt, argv);
	ft_initialize_bitmap(&image, rt.width, rt.height);

	timer = log_start(rt);
	generate_image(&image, rt, rt.camera);
	log_end(timer);
	cleanup_ray_tracer(&rt);

	ft_save_bitmap(&image, rt.file_name);
	ft_free_bitmap(&image);
	return 0;
}
