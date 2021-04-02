/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 19:43:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void initialize_spheres(t_list **spheres)
{
	t_list *first;
	t_list *next;

	t_material *silver   = make_metallic((t_color_3d){0.8, 0.7, 0.7}, 0.0);
	t_material *gold  = make_metallic((t_color_3d){0.8, 0.6, 0.2}, 0.0);

	t_material *matte_red = make_lambertian((t_color_3d){0.7, 0.3, 0.3});
	t_material *matte_green = make_lambertian((t_color_3d){0.3, 0.7, 0.3});
	t_material *matte_blue = make_lambertian((t_color_3d){0.3, 0.3, 0.7});

	first = ft_lstnew(new_sphere((t_point_3d){rp(), rp(), -1.5 + rp()}, rr(), silver));
	int i = 100;
	while (i--)
	{
		next = ft_lstnew(new_sphere((t_point_3d){rp(), rp(), -1.5 + rp()}, rr(), silver));
		ft_lstadd_back(&first, next);
		next = ft_lstnew(new_sphere((t_point_3d){rp(), rp(), -1.5 + rp()}, rr(), gold));
		ft_lstadd_back(&first, next);
		next = ft_lstnew(new_sphere((t_point_3d){rp(), rp(), -1.5 + rp()}, rr(), matte_red));
		ft_lstadd_back(&first, next);
		next = ft_lstnew(new_sphere((t_point_3d){rp(), rp(), -1.5 + rp()}, rr(), matte_green));
		ft_lstadd_back(&first, next);
		next = ft_lstnew(new_sphere((t_point_3d){rp(), rp(), -1.5 + rp()}, rr(), matte_blue));
		ft_lstadd_back(&first, next);
	}

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
