/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:51:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 16:18:52 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

# include <vector.h>

double			random_double(void);
double			random_from(double min, double max);
double			canonical_random(void);

t_vector_3d		random_vector(void);
t_vector_3d		random_vector_in(double min, double max);

#endif
