/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:34:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:47:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

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
