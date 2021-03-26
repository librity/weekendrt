/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 04:19:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 14:14:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc ppm.c && ./a.out hello.ppm

// #include <stdio.h>
#include "./put_fd.h"

int main(int argc, char **argv)
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

	int fd;
	if (argc < 2)
	{
		ft_putstr_fd("error: no file name provided\n", 1);
		return (1);
	}
	fd = open(argv[1], O_CREAT | O_RDWR, 0664);

	// printf("P3\n%d %d\n255\n", image_width, image_height);
	put_header(image_width, image_height, fd);

	while (current_row >= 0)
	{
		current_column = 0;
		while (current_column < image_width)
		{
			red_float = (double)current_column / (image_width - 1);
			green_float = (double)current_row / (image_height - 1);

			red_int = (int)(255.999 * red_float);
			green_int = (int)(255.999 * green_float);

			// printf("%d %d %d\n", red_int, green_int, blue_int);
			put_pixel(red_int, green_int, blue_int, fd);

			current_column++;
		}

		current_row--;
	}
	close(fd);
}
