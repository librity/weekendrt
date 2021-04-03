/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_geometry.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:42:21 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_GEOMETRY_H
# define VECTOR_GEOMETRY_H

# include <vector.h>

bool			near_zero(t_vector_3d vector);

t_vector_3d		reflect(const t_vector_3d incident, const t_vector_3d normal);
t_vector_3d		refract(const t_vector_3d incident,
						const t_vector_3d normal,
						double refration_ration);

#endif
