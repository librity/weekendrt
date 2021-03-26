/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:21:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 17:35:16 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SOURCE: https://github.com/marc-q/libbmp

// make example

#include <stdio.h>
#include "libbmp.h"

int main(int argc, char *argv[])
{
	const int image_width = 1920;
	const int image_height = 1080;

	int current_row = 0;
	int current_column;

	double red_float;
	double green_float;
	double blue_float = 0.75;

	int red_int;
	int green_int;
	int blue_int = (int)(255.999 * blue_float);

	bmp_img img;
	bmp_img_init_df(&img, image_width, image_height);

	while (current_row < image_height)
	{
		current_column = 0;
		while (current_column < image_width)
		{
			red_float = (double)current_column / (image_width - 1);
			green_float = (double)current_row / (image_height - 1);

			red_int = (int)(255.999 * red_float);
			green_int = (int)(255.999 * green_float);

			bmp_pixel_init(&img.img_pixels[current_row][current_column],
						   red_int, green_int, blue_int);

			current_column++;
		}

		current_row++;
	}

	bmp_img_write(&img, "hello.bmp");
	bmp_img_free(&img);
	return 0;
}
