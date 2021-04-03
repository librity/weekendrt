/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_geometry.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 17:00:32 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_GEOMETRY_H
# define VECTOR_GEOMETRY_H

# include <vector.h>

bool			near_zero(t_vector_3d vector);

t_vector_3d		reflect(t_vector_3d incident, t_vector_3d normal);
t_vector_3d		refract(t_vector_3d incident,
						t_vector_3d normal,
						double refration_ration);

#endif
