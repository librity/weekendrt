/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bitmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:10:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 01:21:09 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static t_bitmap_error write_header(t_bitmap_header *header, int file_descriptor)
{
	unsigned short magic = BITMAP_MAGIC_BITS;

	if (header == NULL)
		return HEADER_NOT_INITIALIZED;
	if (file_descriptor < 0)
		return FILE_NOT_OPENED;
	write(file_descriptor, &magic, sizeof(magic));
	write(file_descriptor, header, sizeof(*header));
	return SUCCESS;
}

t_bitmap_error ft_save_bitmap(t_bitmap_image *image, char *filename)
{
	t_bitmap_error header_result;
	int file_descriptor;
	int current_row_index;
	size_t height;
	size_t offset;
	size_t current_row;
	size_t row_width;
	size_t padding_width;
	t_bitmap_pixel *current_row_pixels;
	unsigned char padding[3] = {'\0', '\0', '\0'};

	file_descriptor = open(filename, O_CREAT | O_RDWR, 0664);
	if (file_descriptor < 0)
		return FILE_NOT_OPENED;

	header_result = write_header(&image->header, file_descriptor);
	if (header_result != SUCCESS)
	{
		close(file_descriptor);
		return header_result;
	}

	height = ft_absolute_value(image->header.height);
	offset = (image->header.height > 0 ? height - 1 : 0);

	row_width = sizeof(t_bitmap_pixel) * image->header.width;
	padding_width = sizeof(unsigned char) * ft_calculate_padding(image->header.width);

	current_row = 0;
	while (current_row < height)
	{
		current_row_index = ft_absolute_value((int)offset - (int)current_row);
		current_row_pixels = image->pixels[current_row_index];
		write(file_descriptor, current_row_pixels, row_width);
		write(file_descriptor, padding, padding_width);
		current_row++;
	}

	close(file_descriptor);
	return SUCCESS;
}
