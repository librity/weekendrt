/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 04:54:55 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void inspect(t_vector_3d vector)
{
	printf("%f %f %f\n", vector.x, vector.y, vector.z);
}

double squares_sum(t_vector_3d vector)
{
	double x;
	double y;
	double z;

	x = vector.x * vector.x;
	y = vector.y * vector.y;
	z = vector.z * vector.z;
	return (x + y + z);
}

double length(t_vector_3d vector)
{
	double sum;

	sum = squares_sum(vector);
	return (sqrt(sum));
}

t_vector_3d add(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	return (result);
}

t_vector_3d sub(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x - second.x;
	result.y = first.y - second.y;
	result.z = first.z - second.z;
	return (result);
}

t_vector_3d scalar(double number, t_vector_3d vector)
{
	t_vector_3d result;

	result.x *= number;
	result.y *= number;
	result.z *= number;
	return (result);
}

t_vector_3d scalar_div(double number, t_vector_3d vector)
{
	t_vector_3d result;

	result.x /= number;
	result.y /= number;
	result.z /= number;
	return (result);
}

double dot(t_vector_3d first, t_vector_3d second)
{
	double x;
	double y;
	double z;

	x = first.x * second.x;
	y = first.y * second.y;
	z = first.z * second.z;
	return (x + y + z);
}

t_vector_3d cross(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.y * second.z - first.z * second.y;
	result.y = first.z * second.x - first.x * second.z;
	result.z = first.x * second.y - first.y * second.x;
	return (result);
}

t_vector_3d div(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x / second.x;
	result.y = first.y / second.y;
	result.z = first.z / second.z;
	return (result);
}

t_vector_3d unit(t_vector_3d vector)
{
	double magnitude;

	magnitude = length(vector);
	return (scalar_div(magnitude, vector));
}
