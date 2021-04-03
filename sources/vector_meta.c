/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_meta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:49:56 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:50:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

double		length_squared(t_vector_3d vector)
{
	double x;
	double y;
	double z;

	x = vector.x * vector.x;
	y = vector.y * vector.y;
	z = vector.z * vector.z;
	return (x + y + z);
}

double		length(t_vector_3d vector)
{
	double length_sqrd;

	length_sqrd = length_squared(vector);
	return (sqrt(length_sqrd));
}

t_vector_3d	negative(t_vector_3d vector)
{
	return (scalar_times(-1.0, vector));
}

t_vector_3d	unit(t_vector_3d vector)
{
	double magnitude;

	magnitude = length(vector);
	return (scalar_div(magnitude, vector));
}

t_vector_3d	vsqrt(t_vector_3d vector)
{
	vector.x = sqrt(vector.x);
	vector.y = sqrt(vector.y);
	vector.z = sqrt(vector.z);
	return (vector);
}
