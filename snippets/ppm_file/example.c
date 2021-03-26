/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 04:19:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 17:59:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// make example

#include "libppm.h"

#include <stdlib.h>

static void check_argumnets(int arguments_count)
{
	if (arguments_count < 2)
	{
		ft_putstr_fd("error: no filename\n", 1);
		exit(1);
	}
}

static int create_file(const char *file_name)
{
	int file_descriptor;

	ft_putstr_fd("criando arquivo ", 1);
	ft_putstr_fd(file_name, 1);
	ft_putstr_fd("\n", 1);

	file_descriptor = open(file_name, O_CREAT | O_RDWR, 0664);
	return (file_descriptor);
}

static void write_pixels(int file_descriptor)
{
	const int image_width = 256;
	const int image_height = 256;

	int current_row = image_height - 1;
	int current_column;

	double red_float;
	double green_float;
	double blue_float = 0.75;

	int red_int;
	int green_int;
	int blue_int = (int)(255.999 * blue_float);

	put_header(image_width, image_height, file_descriptor);

	while (current_row >= 0)
	{
		current_column = 0;
		while (current_column < image_width)
		{
			red_float = (double)current_column / (image_width - 1);
			green_float = (double)current_row / (image_height - 1);

			red_int = (int)(255.999 * red_float);
			green_int = (int)(255.999 * green_float);

			put_pixel(red_int, green_int, blue_int, file_descriptor);

			current_column++;
		}

		current_row--;
	}
	close(file_descriptor);
}

int main(int argc, char **argv)
{
	int file_descriptor;

	check_argumnets(argc);
	file_descriptor = create_file(argv[1]);
	write_pixels(file_descriptor);
	return (0);
}
