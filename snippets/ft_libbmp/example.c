/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 22:22:13 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Based on: https://github.com/marc-q/libbmp

// make example

#include <stdio.h>
#include "ft_libbmp.h"

int main(void)
{
	const int width = 1920;
	const int height = 1080;

	int current_row = 0;
	int current_column;

	double red_float;
	double green_float;
	double blue_float = 0.75;

	int red_int;
	int green_int;
	int blue_int = (int)(255.999 * blue_float);

	t_bitmap_image image;
	ft_initialize_bitmap(&image, width, height);

	while (current_row < height)
	{
		current_column = 0;
		while (current_column < width)
		{
			red_float = (double)current_column / (width - 1);
			green_float = (double)current_row / (height - 1);

			red_int = (int)(255.999 * red_float);
			green_int = (int)(255.999 * green_float);

			ft_set_pixel(&image.pixels[current_row][current_column],
						   red_int, green_int, blue_int);

			current_column++;
		}

		current_row++;
	}

	ft_save_bitmap(&image, "hello.bmp");
	ft_free_bitmap(&image);
	return 0;
}
