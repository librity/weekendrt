/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:25:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 15:51:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_factorial(int number)
{
	int factorial;

	if (number < 0)
		return (0);
	if (number == 0 || number == 1)
		return (1);
	factorial = number * ft_factorial(number - 1);
	return (factorial);
}
