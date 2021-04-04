/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libbmp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:23:35 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/04 13:13:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBBMP_H
# define FT_LIBBMP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BITMAP_MAGIC_BITS "BM"

typedef struct	s_bitmap_header
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
}				t_bitmap_header;

typedef struct	s_bitmap_pixel
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}				t_bitmap_pixel;

typedef struct	s_bitmap_image
{
	t_bitmap_header	header;
	t_bitmap_pixel	**pixels;
}				t_bitmap_image;

typedef struct	s_write_pixels
{
	size_t			height;
	size_t			offset;
	size_t			row_width;
	size_t			padding_width;
	unsigned char	padding[3];
}				t_write_pixels;

typedef enum	e_bitmap_error
{
	FILE_NOT_OPENED = 1,
	HEADER_NOT_INITIALIZED,
	BAD_MALLOC,
	GENERIC_BITMAP_ERROR
}				t_bitmap_error;

void			bm_initialize_bitmap(t_bitmap_image *image,
										int width,
										int height);
void			bm_set_pixel(t_bitmap_pixel *pxl,
							unsigned char red,
							unsigned char green,
							unsigned char blue);
void			bm_free_bitmap(t_bitmap_image *img);
void			bm_save_bitmap(t_bitmap_image *image, char *filename);

int				bm_calculate_padding(int number);
int				bm_abs(int number);
void			bm_kill(t_bitmap_error code);

#endif
