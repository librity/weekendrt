/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_meta.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:49:30 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_META_H
# define VECTOR_META_H

# include <vector.h>

double			length_squared(t_vector_3d vector);
double			length(t_vector_3d vector);

t_vector_3d		negative(t_vector_3d vector);
t_vector_3d		unit(t_vector_3d vector);
t_vector_3d		vsqrt(t_vector_3d vector);

#endif
