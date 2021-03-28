/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/28 17:11:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <vector_3d.h>

typedef			t_vector_3d t_color_3d;

typedef struct	s_color_3i
{
	int red;
	int green;
	int blue;
}				t_color_3i;

t_color_3i		color_3d_to_i3(t_color_3d color_3d);
t_color_3i		sample_color_3i(t_color_3d sampled_color,
								int samples_per_pixel);
void			set_image_pixel(t_bitmap_image *image,
								t_color_3i color,
								int row,
								int column);

#endif
