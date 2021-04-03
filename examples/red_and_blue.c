/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_and_blue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 17:29:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void initialize_world(t_list **materials, t_list **spheres)
{
	t_list *first;
	t_list *next;

	t_material *material_left = make_matte((t_color_3d){0.0, 0.0, 1.0});
	t_material *material_right = make_matte((t_color_3d){1.0, 0.0, 0.0});

	first = ft_lstnew(material_left);
	next = ft_lstnew(material_right);
	ft_lstadd_back(&first, next);

	*materials = first;

	double radius = cos(pi() / 4);

	first = ft_lstnew(new_sphere((t_point_3d){-radius, 0.0, -1.0}, radius, material_left));
	next = ft_lstnew(new_sphere( (t_point_3d){ radius, 0.0, -1.0}, radius, material_right));
	ft_lstadd_back(&first, next);

	*spheres = first;
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

	initialize_camera(&(rt->camera), rt->aspect_ratio, 90.0);
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
