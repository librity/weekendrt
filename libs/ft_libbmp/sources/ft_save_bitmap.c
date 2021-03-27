/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bitmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:10:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 01:51:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static void				write_pixels(t_bitmap_image *image, int file_descriptor)
{
	t_write_pixels	control;
	size_t			current_row;
	int				row_index;
	t_bitmap_pixel	*row_pixels;

	control.height = ft_absolute_value(image->header.height);
	control.offset = (image->header.height > 0 ? control.height - 1 : 0);
	control.row_width = sizeof(t_bitmap_pixel) * image->header.width;
	control.padding_width = sizeof(unsigned char) *
								ft_calculate_padding(image->header.width);
	current_row = 0;
	while (current_row < control.height)
	{
		row_index = ft_absolute_value((int)control.offset - (int)current_row);
		row_pixels = image->pixels[row_index];
		write(file_descriptor, row_pixels, control.row_width);
		write(file_descriptor, control.padding, control.padding_width);
		current_row++;
	}
}

static t_bitmap_error	write_header(t_bitmap_header *header,
										int file_descriptor)
{
	unsigned short magic;

	magic = BITMAP_MAGIC_BITS;
	if (header == NULL)
		return (HEADER_NOT_INITIALIZED);
	if (file_descriptor < 0)
		return (FILE_NOT_OPENED);
	write(file_descriptor, &magic, sizeof(magic));
	write(file_descriptor, header, sizeof(*header));
	return (SUCCESS);
}

t_bitmap_error			ft_save_bitmap(t_bitmap_image *image, char *filename)
{
	t_bitmap_error	header_result;
	int				file_descriptor;

	file_descriptor = open(filename, O_CREAT | O_RDWR, 0664);
	if (file_descriptor < 0)
		return (FILE_NOT_OPENED);
	header_result = write_header(&image->header, file_descriptor);
	if (header_result != SUCCESS)
	{
		close(file_descriptor);
		return (header_result);
	}
	write_pixels(image, file_descriptor);
	close(file_descriptor);
	return (SUCCESS);
}
