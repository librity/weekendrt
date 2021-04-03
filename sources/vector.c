/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:19:26 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

t_vector_3d	vector(double x, double y, double z)
{
	return (vector_3d(x, y, z));
}

t_vector_3d	vector_3d(double x, double y, double z)
{
	return ((t_vector_3d){x, y, z});
}

t_point_3d	point(double x, double y, double z)
{
	return (point_3d(x, y, z));
}

t_point_3d	point_3d(double x, double y, double z)
{
	return ((t_point_3d){x, y, z});
}

void		inspect(t_vector_3d vector)
{
	printf("%f %f %f\n", vector.x, vector.y, vector.z);
}

bool		near_zero(t_vector_3d vector)
{
	const float cuttoff = 1e-8;
	bool cuts_off_x = ft_abs_d(vector.x) < cuttoff;
	bool cuts_off_y = ft_abs_d(vector.y) < cuttoff;
	bool cuts_off_z = ft_abs_d(vector.z) < cuttoff;
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

t_vector_3d	refract(const t_vector_3d incident,
					const t_vector_3d normal,
					double refration_ration)
{
	double cos_theta = dot(negative(incident), normal);
	cos_theta = ft_min_d(cos_theta, 1.0);
	t_vector_3d refracted_perpendicular = add(incident, scalar_times(cos_theta, normal));
	refracted_perpendicular = scalar_times(refration_ration, refracted_perpendicular);

	double parallel_magnitude = 1.0 - length_squared(refracted_perpendicular);
	parallel_magnitude = ft_abs_d(parallel_magnitude);
	parallel_magnitude = -sqrt(parallel_magnitude);
	t_vector_3d refracted_parallel = scalar_times(parallel_magnitude, normal);

	t_vector_3d refracted = add(refracted_perpendicular, refracted_parallel);
	return (refracted);
}
