/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:51:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 00:53:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_UTILS_H
# define RANDOM_UTILS_H

# include <color.h>

double			rp(void);
double			rr(void);
t_color_3d		rc(void);
t_color_3d		rcr(double min, double max);

#endif
