/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:50:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 17:06:28 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

double		random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double		random_from(double min, double max)
{
	return (min + (max - min) * random_double());
}

double		canonical_random(void)
{
	return (random_from(0.0, 1.0));
}

t_vector_3d	random_vector(void)
{
	return (vector(random_double(), random_double(), random_double()));
}

t_vector_3d	random_vector_in(double min, double max)
{
	return (vector(random_from(min, max),
							random_from(min, max),
							random_from(min, max)));
}
