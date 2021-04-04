/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/04 01:45:10 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void initialize_world(t_list **materials, t_list **spheres)
{
	create_matte_sphere(
		(t_sphere_params){
			materials, spheres,
			point(rp(), rp(), -1.5 + rp()), rr(),
			rc(), 0.0, 0.0});

	int i = 120;
	while (i--)
	{
		add_matte_sphere(
			(t_sphere_params){
				materials, spheres,
				point(rp(), rp(), -1.5 + rp()), rr(),
				rc(), 0.0, 0.0});

		add_metallic_sphere(
			(t_sphere_params){
				materials, spheres,
				point(rp(), rp(), -1.5 + rp()), rr(),
				rc(), random_from(0.0, 1.0), 0.0});

		add_dielectric_sphere(
			(t_sphere_params){
				materials, spheres,
				point(rp(), rp(), -1.5 + rp()), rr(),
				color(0, 0, 0), 0.0, random_from(1.4, 1.6)});
	}
}

static void configure_camera(t_ray_tracer *rt)
{
	t_camera_params camera_params;

	camera_params.look_from = (t_point_3d){0.0, 0.0, 0.0};
	camera_params.look_at = (t_point_3d){0.0, 0.0, -1.0};
	camera_params.view_up = (t_vector_3d){0.0, 1.0, 0.0};

	camera_params.vertical_fov_degrees = 90.0;
	camera_params.aperture = 0.0;
	camera_params.focus_distance = 2.0;

	initialize_camera(&(rt->camera), rt->aspect_ratio, camera_params);
}

static void initialize_ray_tracer(t_ray_tracer *rt, char **arguments)
{
	rt->file_name = arguments[1];

	rt->aspect_ratio = 16.0 / 9.0;
	rt->width = 1920;
	// rt->width = 400;
	rt->height = (int)(rt->width / rt->aspect_ratio);
	rt->samples_per_pixel = 100;
	rt->max_depth = 50;

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
	bm_initialize_bitmap(&image, rt.width, rt.height);

	timer = log_start(rt);
	generate_image(&image, rt, rt.camera);
	log_end(timer);
	cleanup_ray_tracer(&rt);

	bm_save_bitmap(&image, rt.file_name);
	bm_free_bitmap(&image);
	return 0;
}
