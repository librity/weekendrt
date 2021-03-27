/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 21:56:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Based on: https://github.com/marc-q/libbmp

#ifndef FT_LIBBMP_H
# define FT_LIBBMP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BITMAP_MAGIC_BITS 0x4D42

typedef enum s_bitmap_error
{
	FILE_NOT_OPENED = -4,
	HEADER_NOT_INITIALIZED,
	INVALID_FILE,
	GENERIC_ERROR,
	SUCCESS = 0
} t_bitmap_error;

typedef struct s_bitmap_header
{
	unsigned int	buffer_size;
	unsigned int	buffer_reserved;
	unsigned int	buffer_offset;

	unsigned int	total_size;
	int				width;
	int				height;

	unsigned short	planes;
	unsigned short	bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	int				x_resolution_ppm;
	int				y_resolution_ppm;
	unsigned int	colors_used;
	unsigned int	important_colors;
} t_bitmap_header;

typedef struct s_bitmap_pixel
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} t_bitmap_pixel;

typedef struct s_bitmap_image
{
	t_bitmap_header img_header;
	t_bitmap_pixel **img_pixels;
} t_bitmap_image;

void			ft_initialize_bitmap(t_bitmap_image *img, const int width, const int height);
void			ft_set_pixel(t_bitmap_pixel *pxl, const unsigned char red, const unsigned char green, const unsigned char blue);
void			ft_free_bitmap(t_bitmap_image *img);
t_bitmap_error	ft_save_bitmap(const t_bitmap_image *img, const char *filename);

#endif
