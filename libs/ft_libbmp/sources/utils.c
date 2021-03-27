/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:17:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 01:41:58 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

int		ft_calculate_padding(int number)
{
	return (number % 4);
}

int		ft_absolute_value(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

void	ft_set_pixel(t_bitmap_pixel *pxl,
						unsigned char red,
						unsigned char green,
						unsigned char blue)
{
	pxl->red = red;
	pxl->green = green;
	pxl->blue = blue;
}
