/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_focus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 15:54:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void initialize_world(t_list **materials, t_list **spheres)
{
	t_list *first;
	t_list *next;

	t_material *lime_green_matte = make_matte((t_color_3d){0.8, 0.8, 0.0});
	t_material *glass   = make_dielectric(1.5);
	t_material *blue_matte = make_matte((t_color_3d){0.1, 0.2, 0.5});
	t_material *gold  = make_metallic((t_color_3d){0.8, 0.6, 0.2}, 0.0);

	first = ft_lstnew(lime_green_matte);
	next = ft_lstnew(glass);
	ft_lstadd_back(&first, next);
	next = ft_lstnew(blue_matte);
	ft_lstadd_back(&first, next);
	next = ft_lstnew(gold);
	ft_lstadd_back(&first, next);

	*materials = first;

	first = ft_lstnew(new_sphere((t_point_3d){ 0.0, -100.5, -1.0}, 100.0, lime_green_matte));
	next = ft_lstnew(new_sphere( (t_point_3d){-1.0,    0.0, -1.0},   0.5, glass));
	ft_lstadd_back(&first, next);
	next = ft_lstnew(new_sphere( (t_point_3d){-1.0,    0.0, -1.0}, -0.45, glass));
	ft_lstadd_back(&first, next);
	next = ft_lstnew(new_sphere( (t_point_3d){ 0.0,    0.0, -1.0},   0.5, blue_matte));
	ft_lstadd_back(&first, next);
	next = ft_lstnew(new_sphere( (t_point_3d){ 1.0,    0.0, -1.0},   0.5, gold));
	ft_lstadd_back(&first, next);

	*spheres = first;
}

static void configure_camera(t_ray_tracer *rt)
{
	t_camera_params camera_params;

	camera_params.look_from = (t_point_3d){3, 3, 2};
	camera_params.look_at = (t_point_3d){0, 0, -1};
	camera_params.view_up = (t_vector_3d){0, 1, 0};

	camera_params.vertical_fov_degrees = 20.0;
	camera_params.aperture = 2.0;
	camera_params.focus_distance = length(
		sub(camera_params.look_from, camera_params.look_at)
	);

	initialize_camera(&(rt->camera), rt->aspect_ratio, camera_params);
}

static void initialize_ray_tracer(t_ray_tracer *rt, char **arguments)
{
	rt->file_name = arguments[1];

	rt->aspect_ratio = 16.0 / 9.0;
	rt->width = 1920;
	// rt->width = 400;
	rt->height = (int)(rt->width / rt->aspect_ratio);
	rt->samples_per_pixel = 10;
	// rt->samples_per_pixel = 100;
	rt->max_depth = 50;

	configure_camera(rt);
	initialize_world(&(rt->materials), &(rt->spheres));
}

int main(int argc, char **argv)
{
	t_ray_tracer rt;
	t_bitmap_image image;

	handle_arguments(argc);
	initialize_ray_tracer(&rt, argv);
	bm_initialize_bitmap(&image, rt.width, rt.height);

	ft_putstr("Scaning lines: ");
	generate_image(&image, rt, rt.camera);
	ft_putstr(" Done!\n");
	cleanup_ray_tracer(&rt);

	bm_save_bitmap(&image, rt.file_name);
	bm_free_bitmap(&image);
	return 0;
}
