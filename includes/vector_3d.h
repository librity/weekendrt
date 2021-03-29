/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/29 03:38:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_3D_H
# define VECTOR_3D_H

# include <stdio.h>
# include <math.h>

typedef struct	s_vector_3d
{
	double x;
	double y;
	double z;
}				t_vector_3d;

typedef			t_vector_3d t_point_3d;

void			inspect(t_vector_3d vector);

double			length_squared(t_vector_3d vector);
double			length(t_vector_3d vector);
double			dot(t_vector_3d first, t_vector_3d second);

t_vector_3d		scalar_add(double number, t_vector_3d vector);
t_vector_3d		scalar_sub(double number, t_vector_3d vector);
t_vector_3d		scalar_times(double number, t_vector_3d vector);
t_vector_3d		scalar_div(double number, t_vector_3d vector);
t_vector_3d		negative(t_vector_3d vector);

t_vector_3d		add(t_vector_3d first, t_vector_3d second);
t_vector_3d		sub(t_vector_3d first, t_vector_3d second);
t_vector_3d		cross(t_vector_3d first, t_vector_3d second);
t_vector_3d		dot_div(t_vector_3d first, t_vector_3d second);
t_vector_3d		unit(t_vector_3d vector);

#endif
