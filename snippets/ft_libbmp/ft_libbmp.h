/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 18:22:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Based on: https://github.com/marc-q/libbmp

#ifndef FT_LIBBMP_H
# define FT_LIBBMP_H

# include <stdio.h>
# include <stdlib.h>

# define BMP_MAGIC 0x4D42

// This is faster than a function call
# define BMP_GET_PADDING(a) ((a) % 4)
# define BMP_PIXEL(r, g, b) ((bmp_pixel){(b), (g), (r)})

typedef enum bmp_error
{
	BMP_FILE_NOT_OPENED = -4,
	BMP_HEADER_NOT_INITIALIZED,
	BMP_INVALID_FILE,
	BMP_ERROR,
	BMP_OK = 0
} t_bmp_error;

typedef struct _bmp_header
{
	unsigned int bfSize;
	unsigned int bfReserved;
	unsigned int bfOffBits;

	unsigned int biSize;
	int biWidth;
	int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	unsigned int biClrUsed;
	unsigned int biClrImportant;
} bmp_header;

typedef struct _bmp_pixel
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} bmp_pixel;

typedef struct _bmp_img
{
	bmp_header img_header;
	bmp_pixel **img_pixels;
} bmp_img;

// BMP_HEADER
void bmp_header_init_df(bmp_header *,
						const int,
						const int);

enum bmp_error bmp_header_write(const bmp_header *,
								FILE *);

enum bmp_error bmp_header_read(bmp_header *,
							   FILE *);

// BMP_PIXEL
void bmp_pixel_init(bmp_pixel *,
					const unsigned char,
					const unsigned char,
					const unsigned char);

// BMP_IMG
void bmp_img_alloc(bmp_img *);
void bmp_img_init_df(bmp_img *,
					 const int,
					 const int);
void bmp_img_free(bmp_img *);

enum bmp_error ft_write_bmp_image(const bmp_img *,
							 const char *);

enum bmp_error bmp_img_read(bmp_img *,
							const char *);

#endif
