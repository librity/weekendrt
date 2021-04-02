/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/02 16:22:48 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

void		inspect(t_vector_3d vector)
{
	printf("%f %f %f\n", vector.x, vector.y, vector.z);
}

bool		near_zero(t_vector_3d vector)
{
	const float cuttoff = 1e-8;
	bool cuts_off_x = ft_absolute_value_f(vector.x) < cuttoff;
	bool cuts_off_y = ft_absolute_value_f(vector.y) < cuttoff;
	bool cuts_off_z = ft_absolute_value_f(vector.z) < cuttoff;
	return (cuts_off_x && cuts_off_y && cuts_off_z);
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

t_vector_3d	product(t_vector_3d first, t_vector_3d second)
{
	t_vector_3d result;

	result.x = first.x * second.x;
	result.y = first.y * second.y;
	result.z = first.z * second.z;
	return (result);
}

t_vector_3d	division(t_vector_3d first, t_vector_3d second)
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

t_vector_3d	reflect(const t_vector_3d incident, const t_vector_3d normal)
{
	double factor = 2.0 * dot(incident, normal);
	t_vector_3d complement = scalar_times(factor, normal);
	return (sub(incident, complement));
}
