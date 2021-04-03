/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:17:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 15:54:00 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

int		bm_calculate_padding(int number)
{
	return (number % 4);
}

int		bm_abs(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

void	bm_set_pixel(t_bitmap_pixel *pxl,
						unsigned char red,
						unsigned char green,
						unsigned char blue)
{
	pxl->red = red;
	pxl->green = green;
	pxl->blue = blue;
}
