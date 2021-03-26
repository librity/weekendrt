/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 18:24:15 by lpaulo-m         ###   ########.fr       */
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

t_bmp_error bmp_header_write(const bmp_header *header,
				 FILE *img_file)
{
	if (header == NULL)
		return BMP_HEADER_NOT_INITIALIZED;
	if (img_file == NULL)
		return BMP_FILE_NOT_OPENED;

	// Since an adress must be passed to fwrite, create a variable!
	const unsigned short magic = BMP_MAGIC;
	fwrite(&magic, sizeof(magic), 1, img_file);

	// Use the type instead of the variable because its a pointer!
	fwrite(header, sizeof(bmp_header), 1, img_file);
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
	FILE *img_file = fopen(filename, "wb");

	if (img_file == NULL)
	{
		return BMP_FILE_NOT_OPENED;
	}

	// NOTE: This way the correct error code could be returned.
	const t_bmp_error err = bmp_header_write(&img->img_header, img_file);

	if (err != BMP_OK)
	{
		// ERROR: Could'nt write the header!
		fclose(img_file);
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
		fwrite(img->img_pixels[abs((int)offset - (int)y)], sizeof(bmp_pixel), img->img_header.biWidth, img_file);

		// Write the padding for the row!
		fwrite(padding, sizeof(unsigned char), BMP_GET_PADDING(img->img_header.biWidth), img_file);
	}

	// NOTE: All good!
	fclose(img_file);
	return BMP_OK;
}
