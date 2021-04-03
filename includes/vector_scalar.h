/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:48:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_SCALAR_H
# define VECTOR_SCALAR_H

# include <vector.h>

t_vector_3d		scalar_add(double number, t_vector_3d vector);
t_vector_3d		scalar_sub(double number, t_vector_3d vector);
t_vector_3d		scalar_times(double number, t_vector_3d vector);
t_vector_3d		scalar_div(double number, t_vector_3d vector);

double			dot(t_vector_3d first, t_vector_3d second);

#endif
