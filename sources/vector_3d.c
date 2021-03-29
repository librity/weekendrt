/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/29 04:18:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void		inspect(t_vector_3d vector)
{
	printf("%f %f %f\n", vector.x, vector.y, vector.z);
}

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

t_vector_3d	scalar_add(double number, t_vector_3d vector)
{
	vector.x += number;
	vector.y += number;
	vector.z += number;
	return (vector);
}

t_vector_3d	scalar_sub(double number, t_vector_3d vector)
{
	vector.x -= number;
	vector.y -= number;
	vector.z -= number;
	return (vector);
}

t_vector_3d	scalar_times(double number, t_vector_3d vector)
{
	vector.x *= number;
	vector.y *= number;
	vector.z *= number;
	return (vector);
}

t_vector_3d	scalar_div(double number, t_vector_3d vector)
{
	vector.x /= number;
	vector.y /= number;
	vector.z /= number;
	return (vector);
}

t_vector_3d	negative(t_vector_3d vector)
{
	return (scalar_times(-1.0, vector));
}

t_vector_3d	add(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	return (result);
}

t_vector_3d	sub(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x - second.x;
	result.y = first.y - second.y;
	result.z = first.z - second.z;
	return (result);
}

double		dot(t_vector_3d first, t_vector_3d second)
{
	double x;
	double y;
	double z;

	x = first.x * second.x;
	y = first.y * second.y;
	z = first.z * second.z;
	return (x + y + z);
}

t_vector_3d	cross(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.y * second.z - first.z * second.y;
	result.y = first.z * second.x - first.x * second.z;
	result.z = first.x * second.y - first.y * second.x;
	return (result);
}

t_vector_3d	dot_div(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x / second.x;
	result.y = first.y / second.y;
	result.z = first.z / second.z;
	return (result);
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
