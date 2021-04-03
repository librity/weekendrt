/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 15:54:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static print_error(char *message)
{
	while (*message)
		write(1, message++, 1);
}

typedef struct s_example
{
	char *file_name;

	int width;
	int height;

	double red_float;
	double green_float;
	double blue_float;

	int red_int;
	int green_int;
	int blue_int;

} t_example;

static void initialize_control(t_example *control, char **arguments)
{
	control->file_name = arguments[1];

	control->width = 1920;
	control->height = 1080;

	control->blue_float = 0.75;
	control->blue_int = (int)(255.999 * control->blue_float);
}

static void set_pixels(t_bitmap_image *image, t_example *c)
{
	int current_row;
	int current_column;

	current_row = 0;
	while (current_row < c->height)
	{
		current_column = 0;
		while (current_column < c->width)
		{
			c->red_float = (double)current_column / (c->width - 1);
			c->green_float = (double)current_row / (c->height - 1);

			c->red_int = (int)(255.999 * c->red_float);
			c->green_int = (int)(255.999 * c->green_float);

			bm_set_pixel(&image->pixels[current_row][current_column],
						 c->red_int, c->green_int, c->blue_int);

			current_column++;
		}

		current_row++;
	}
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
	bm_initialize_bitmap(&image, c.width, c.height);
	set_pixels(&image, &c);
	bm_save_bitmap(&image, c.file_name);
	bm_free_bitmap(&image);
	return 0;
}
