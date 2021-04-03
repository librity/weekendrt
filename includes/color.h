/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:17:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <vector.h>

typedef t_vector_3d	t_color_3d;

typedef struct	s_color_3i
{
	int red;
	int green;
	int blue;
}				t_color_3i;

t_color_3d		color(double red, double green, double blue);
t_color_3d		color_3d(double red, double green, double blue);
t_color_3i		color_3i(int red, int green, int blue);

t_color_3i		color_3d_to_i3(t_color_3d color_3d);

#endif
