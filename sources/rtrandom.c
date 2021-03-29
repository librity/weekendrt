/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtrandom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:50:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/29 04:03:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

double	random_double(void)
{
	return rand() / (RAND_MAX + 1.0);
}

double	random_from(double min, double max)
{
	return min + (max - min) * random_double();
}

double	rp(void)
{
	return (random_from(-1.0, 1.0));
}

double	rr(void)
{
	return (random_from(0.0, 0.1));
}

double	canonical_random(void)
{
	return (random_from(0.0, 1.0));
}

t_vector_3d	random_vector(void)
{
	return ((t_vector_3d){random_double(), random_double(), random_double()});
}

t_vector_3d	random_vector_in(double min, double max)
{
	return ((t_vector_3d){random_from(min, max),
							random_from(min, max),
							random_from(min, max)});
}

t_point_3d		random_point_in_unit_sphere(void)
{
	t_point_3d random;
	while (true)
	{
		random = random_vector_in(-1.0, 1.0);
		if (length_squared(random) >= 1)
			continue ;
		return (random);
	}
}
