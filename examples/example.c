/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 18:17:31 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void initialize_spheres(t_list **spheres)
{
	t_list *first;
	t_list *next;

	first = ft_lstnew(new_sphere((t_point_3d){0.0, -100.5, -1.0}, 100.0));
	next = ft_lstnew(new_sphere((t_point_3d){0.0, 0.0, -1.0}, 0.5));
	ft_lstadd_back(&first, next);

	*spheres = first;
}

static void initialize_ray_tracer(t_ray_tracer *rt, char **arguments)
{
	rt->file_name = arguments[1];

	rt->aspect_ratio = 16.0 / 9.0;
	rt->width = 1920;
	rt->height = (int)(rt->width / rt->aspect_ratio);
	rt->samples_per_pixel = 10;

	initialize_camera(&(rt->camera), rt->aspect_ratio);
	initialize_spheres(&(rt->spheres));
}

int main(int argc, char **argv)
{
	t_ray_tracer rt;
	t_bitmap_image image;

	handle_arguments(argc);
	initialize_ray_tracer(&rt, argv);
	ft_initialize_bitmap(&image, rt.width, rt.height);

	ft_putstr("Scaning lines: ");
	generate_image(&image, rt, rt.camera);
	ft_putstr(" Done!\n");
	free_spheres(&(rt.spheres));

	ft_save_bitmap(&image, rt.file_name);
	ft_free_bitmap(&image);
	return 0;
}
