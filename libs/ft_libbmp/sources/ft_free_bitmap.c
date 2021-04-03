/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bitmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:15:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 15:54:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

void	bm_free_bitmap(t_bitmap_image *image)
{
	size_t height;
	size_t current_row;

	height = bm_abs(image->header.height);
	current_row = 0;
	while (current_row < height)
		free(image->pixels[current_row++]);
	free(image->pixels);
}
