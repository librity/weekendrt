/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 19:58:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Based on: https://github.com/marc-q/libbmp

#include "ft_libbmp.h"

// BMP_HEADER

void bmp_header_init_df(bmp_header *header,
						const int width,
						const int height)
{
	header->bfSize = (sizeof(bmp_pixel) * width + BMP_GET_PADDING(width)) * abs(height);
	header->bfReserved = 0;
	header->bfOffBits = 54;
	header->biSize = 40;
	header->biWidth = width;
	header->biHeight = height;
	header->biPlanes = 1;
	header->biBitCount = 24;
	header->biCompression = 0;
	header->biSizeImage = 0;
	header->biXPelsPerMeter = 0;
	header->biYPelsPerMeter = 0;
	header->biClrUsed = 0;
	header->biClrImportant = 0;
}

t_bmp_error bmp_header_write(const bmp_header *header, int file_descriptor)
{
	if (header == NULL)
		return BMP_HEADER_NOT_INITIALIZED;
	if (file_descriptor < 0)
		return BMP_FILE_NOT_OPENED;

	// Since an adress must be passed to fwrite, create a variable!
	const unsigned short magic = BMP_MAGIC;
	write(file_descriptor, &magic, sizeof(magic));

	// Use the type instead of the variable because its a pointer!
	write(file_descriptor, header, sizeof(bmp_header));
	return BMP_OK;
}

// BMP_PIXEL

void bmp_pixel_init(bmp_pixel *pxl,
					const unsigned char red,
					const unsigned char green,
					const unsigned char blue)
{
	pxl->red = red;
	pxl->green = green;
	pxl->blue = blue;
}

// BMP_IMG

void bmp_img_alloc(bmp_img *img)
{
	const size_t h = abs(img->img_header.biHeight);

	// Allocate the required memory for the pixels:
	img->img_pixels = malloc(sizeof(bmp_pixel *) * h);

	for (size_t y = 0; y < h; y++)
		img->img_pixels[y] = malloc(sizeof(bmp_pixel) * img->img_header.biWidth);
}

void bmp_img_init_df(bmp_img *img,
					 const int width,
					 const int height)
{
	// INIT the header with default values:
	bmp_header_init_df(&img->img_header, width, height);
	bmp_img_alloc(img);
}

void bmp_img_free(bmp_img *img)
{
	const size_t h = abs(img->img_header.biHeight);

	for (size_t y = 0; y < h; y++)
		free(img->img_pixels[y]);
	free(img->img_pixels);
}

t_bmp_error ft_write_bmp_image(const bmp_img *img,
							   const char *filename)
{
	int file_descriptor = open(filename, O_CREAT | O_RDWR, 0664);

	if (file_descriptor < 0)
		return BMP_FILE_NOT_OPENED;

	// NOTE: This way the correct error code could be returned.
	const t_bmp_error err = bmp_header_write(&img->img_header, file_descriptor);

	if (err != BMP_OK)
	{
		// ERROR: Could'nt write the header!
		close(file_descriptor);
		return err;
	}

	// Select the mode (bottom-up or top-down):
	const size_t h = abs(img->img_header.biHeight);
	const size_t offset = (img->img_header.biHeight > 0 ? h - 1 : 0);

	// Create the padding:
	const unsigned char padding[3] = {'\0', '\0', '\0'};

	// Write the content:
	for (size_t y = 0; y < h; y++)
	{
		// Write a whole row of pixels to the file:
		write(file_descriptor, img->img_pixels[abs((int)offset - (int)y)], sizeof(bmp_pixel) * img->img_header.biWidth);

		// Write the padding for the row!
		write(file_descriptor, padding, sizeof(unsigned char) * BMP_GET_PADDING(img->img_header.biWidth));
	}

	// NOTE: All good!
	close(file_descriptor);
	return BMP_OK;
}
