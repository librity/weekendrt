/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 04:28:11 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

# include <color.h>

t_color_3d		scale_and_gamma2_correct(t_color_3d sampled_color,
											const double scale);
t_color_3i		sample_pixel_color(t_color_3d sampled_color,
									int samples_per_pixel);
void			set_image_pixel(t_bitmap_image *image,
								t_color_3i color,
								int row,
								int column);

#endif
