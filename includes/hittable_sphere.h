/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_sphere.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:55:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 18:36:59 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_SPHERE_H
# define HITTABLE_SPHERE_H

# include <sphere.h>

typedef struct	s_vectorial_quadratic_params
{
	t_ray		ray;
	t_sphere	*sphere;

	double		min_translation;
	double		max_translation;

	double		*root;
}				t_vectorial_quadratic_params;

typedef struct	s_ray_hits_sphere_params
{
	t_ray			ray;
	t_sphere		*sphere;
	t_hit_record	*record;

	double			t_min;
	double			t_max;
}				t_ray_hits_sphere_params;

bool			ray_hits_sphere(t_ray_hits_sphere_params p);

#endif
