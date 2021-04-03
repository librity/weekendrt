/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:39:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:44:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS_H
# define VECTOR_OPERATIONS_H

# include <vector.h>

t_vector_3d		add(t_vector_3d first, t_vector_3d second);
t_vector_3d		sub(t_vector_3d first, t_vector_3d second);
t_vector_3d		cross(t_vector_3d first, t_vector_3d second);
t_vector_3d		product(t_vector_3d first, t_vector_3d second);
t_vector_3d		division(t_vector_3d first, t_vector_3d second);

#endif
