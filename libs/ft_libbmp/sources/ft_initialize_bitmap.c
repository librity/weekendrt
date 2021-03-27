/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_bitmap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:12:49 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 01:22:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static void allocate_pixels(t_bitmap_image *image)
{
	size_t height;
	size_t current_row;
	size_t row_size;

	height = ft_absolute_value(image->header.height);
	image->pixels = malloc(sizeof(t_bitmap_pixel *) * height);
	row_size = sizeof(t_bitmap_pixel) * image->header.width;
	current_row = 0;
	while (current_row < height)
		image->pixels[current_row++] = malloc(row_size);
}

static void initialize_header(t_bitmap_header *header,
							  int width,
							  int height)
{
	size_t adjusted_width;
	size_t positive_height;

	adjusted_width = ft_calculate_padding(width) + sizeof(t_bitmap_pixel) * width;
	positive_height = ft_absolute_value(height);
	header->buffer_size = adjusted_width * positive_height;
	header->buffer_reserved = 0;
	header->buffer_offset = 54;
	header->total_size = 40;
	header->width = width;
	header->height = height;
	header->planes = 1;
	header->bit_count = 24;
	header->compression = 0;
	header->image_size = 0;
	header->x_resolution_ppm = 0;
	header->y_resolution_ppm = 0;
	header->colors_used = 0;
	header->important_colors = 0;
}

void ft_initialize_bitmap(t_bitmap_image *image, int width, int height)
{
	initialize_header(&image->header, width, height);
	allocate_pixels(image);
}
