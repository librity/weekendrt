/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 15:18:12 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>
#include <stdio.h>

static void print_error(char *message)
{
	while (*message)
		write(1, message++, 1);
}

typedef struct s_example
{
	char *file_name;

	int width;
	int height;
} t_example;

static void initialize_control(t_example *control, char **arguments)
{
	control->file_name = arguments[1];

	control->width = 1920;
	control->height = 1080;
}

static void set_pixels(t_bitmap_image *image, t_example *c)
{
	t_color_3d color_3d;
	t_color_3i color_3i;

	int current_row;
	int current_column;

	printf("Scaning lines: ");
	current_row = 0;
	while (current_row < c->height)
	{
		printf("▒");

		current_column = 0;
		while (current_column < c->width)
		{
			color_3d.x = (double)current_column / (c->width - 1);
			color_3d.y = (double)current_row / (c->height - 1);
			color_3d.z = 0.75;

			color_3i = color_3d_to_i3(color_3d);

			ft_set_pixel(&image->pixels[current_row][current_column],
						 color_3i.red, color_3i.green, color_3i.blue);

			current_column++;
		}

		current_row++;
	}

	printf("\nDone.\n");
}

static void handle_arguments(int argument_count)
{
	if (argument_count != 2)
	{
		print_error("ERROR: expected one argument as filename.\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	t_example c;
	t_bitmap_image image;

	handle_arguments(argc);
	initialize_control(&c, argv);
	ft_initialize_bitmap(&image, c.width, c.height);
	set_pixels(&image, &c);
	ft_save_bitmap(&image, c.file_name);
	ft_free_bitmap(&image);
	return 0;
}
