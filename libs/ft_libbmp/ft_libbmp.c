/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 22:30:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Based on: https://github.com/marc-q/libbmp

#include "ft_libbmp.h"

static int get_padding(int number)
{
	return (number % 4);
}

static int absolute_value(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

static void initialize_header(t_bitmap_header *header,
								const int width,
								const int height)
{
	header->buffer_size = (sizeof(t_bitmap_pixel) * width + get_padding(width)) * absolute_value(height);
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

static t_bitmap_error write_header(const t_bitmap_header *header, int file_descriptor)
{
	const unsigned short magic = BITMAP_MAGIC_BITS;

	if (header == NULL)
		return HEADER_NOT_INITIALIZED;
	if (file_descriptor < 0)
		return FILE_NOT_OPENED;
	write(file_descriptor, &magic, sizeof(magic));
	write(file_descriptor, header, sizeof(*header));
	return SUCCESS;
}

static void allocate_pixels(t_bitmap_image *image)
{
	const size_t positive_height = absolute_value(image->header.height);

	image->pixels = malloc(sizeof(t_bitmap_pixel *) * positive_height);
	for (size_t current_row = 0; current_row < positive_height; current_row++)
		image->pixels[current_row] = malloc(sizeof(t_bitmap_pixel) * image->header.width);
}

void ft_initialize_bitmap(t_bitmap_image *image,
							const int width,
							const int height)
{
	initialize_header(&image->header, width, height);
	allocate_pixels(image);
}

void ft_set_pixel(t_bitmap_pixel *pxl,
					const unsigned char red,
					const unsigned char green,
					const unsigned char blue)
{
	pxl->red = red;
	pxl->green = green;
	pxl->blue = blue;
}

void ft_free_bitmap(t_bitmap_image *image)
{
	const size_t	height = absolute_value(image->header.height);
	size_t			current_row;

	current_row = 0;
	while (current_row++ < height)
		free(image->pixels[current_row]);
	free(image->pixels);
}

t_bitmap_error ft_save_bitmap(const t_bitmap_image *image,
							  const char *filename)
{
	t_bitmap_error		header_write_result;
	int					file_descriptor;
	int					current_row_index;
	size_t				height;
	size_t				offset;
	size_t				current_row;
	size_t				row_width;
	size_t				padding_width;
	t_bitmap_pixel		*current_row_pixels;
	const unsigned char	padding[3] = {'\0', '\0', '\0'};

	file_descriptor = open(filename, O_CREAT | O_RDWR, 0664);
	if (file_descriptor < 0)
		return FILE_NOT_OPENED;

	header_write_result = write_header(&image->header, file_descriptor);
	if (header_write_result != SUCCESS)
	{
		close(file_descriptor);
		return header_write_result;
	}

	height = absolute_value(image->header.height);
	offset = (image->header.height > 0 ? height - 1 : 0);

	row_width = sizeof(t_bitmap_pixel) * image->header.width;
	padding_width = sizeof(unsigned char) * get_padding(image->header.width);

	current_row = 0;
	while (current_row++ < height)
	{
		current_row_index = absolute_value((int)offset - (int)current_row);
		current_row_pixels = image->pixels[current_row_index];
		write(file_descriptor, current_row_pixels, row_width);
		write(file_descriptor, padding, padding_width);
	}

	close(file_descriptor);
	return SUCCESS;
}
