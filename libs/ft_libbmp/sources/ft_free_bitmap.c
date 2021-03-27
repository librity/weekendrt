/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bitmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:15:39 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 01:22:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

void ft_free_bitmap(t_bitmap_image *image)
{
	size_t height = ft_absolute_value(image->header.height);
	size_t current_row;

	current_row = 0;
	while (current_row < height)
		free(image->pixels[current_row++]);
	free(image->pixels);
}
