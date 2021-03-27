/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 21:57:19 by lpaulo-m         ###   ########.fr       */
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
	// header->bitmap_magic_bits = 0x4D42;
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

static void allocate_pixels(t_bitmap_image *img)
{
	const size_t positive_height = absolute_value(img->img_header.height);

	img->img_pixels = malloc(sizeof(t_bitmap_pixel *) * positive_height);
	for (size_t y = 0; y < positive_height; y++)
		img->img_pixels[y] = malloc(sizeof(t_bitmap_pixel) * img->img_header.width);
}

void ft_initialize_bitmap(t_bitmap_image *img,
						  const int width,
						  const int height)
{
	initialize_header(&img->img_header, width, height);
	allocate_pixels(img);
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

void ft_free_bitmap(t_bitmap_image *img)
{
	const size_t height = absolute_value(img->img_header.height);

	for (size_t y = 0; y < height; y++)
		free(img->img_pixels[y]);
	free(img->img_pixels);
}

t_bitmap_error ft_save_bitmap(const t_bitmap_image *img,
							  const char *filename)
{
	int file_descriptor;

	file_descriptor = open(filename, O_CREAT | O_RDWR, 0664);
	if (file_descriptor < 0)
		return FILE_NOT_OPENED;

	// NOTE: This way the correct error code could be returned.
	const t_bitmap_error err = write_header(&img->img_header, file_descriptor);

	if (err != SUCCESS)
	{
		// ERROR: Could'nt write the header!
		close(file_descriptor);
		return err;
	}

	// Select the mode (bottom-up or top-down):
	const size_t h = absolute_value(img->img_header.height);
	const size_t offset = (img->img_header.height > 0 ? h - 1 : 0);

	// Create the padding:
	const unsigned char padding[3] = {'\0', '\0', '\0'};

	// Write the content:
	for (size_t y = 0; y < h; y++)
	{
		// Write a whole row of pixels to the file:
		write(file_descriptor, img->img_pixels[absolute_value((int)offset - (int)y)], sizeof(t_bitmap_pixel) * img->img_header.width);

		// Write the padding for the row!
		write(file_descriptor, padding, sizeof(unsigned char) * get_padding(img->img_header.width));
	}

	// NOTE: All good!
	close(file_descriptor);
	return SUCCESS;
}
