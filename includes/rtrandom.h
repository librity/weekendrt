/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtrandom.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:51:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 01:36:25 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTRANDOM_H
# define RTRANDOM_H

# include <vector_3d.h>

t_vector_3d		vector(double x, double y, double z);
t_vector_3d		vector_3d(double x, double y, double z);
t_point_3d		point(double x, double y, double z);
t_point_3d		point_3d(double x, double y, double z);

double			random_double(void);
double			random_from(double min, double max);
double			canonical_random(void);

t_vector_3d		random_vector(void);
t_vector_3d		random_vector_in(double min, double max);
t_vector_3d		random_unit_vector(void);

t_point_3d		random_in_unit_sphere(void);
t_point_3d		random_in_unit_disk(void);
t_vector_3d		random_in_hemisphere(const t_vector_3d normal);

#endif
