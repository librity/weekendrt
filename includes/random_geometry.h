/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_geometry.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:51:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:18:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_GEOMETRY_H
# define RANDOM_GEOMETRY_H

# include <vector.h>

t_vector_3d		random_unit_vector(void);

t_point_3d		random_in_unit_sphere(void);
t_point_3d		random_in_unit_disk(void);
t_vector_3d		random_in_hemisphere(const t_vector_3d normal);

#endif
