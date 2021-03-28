/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:22:16 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/25 20:02:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	ft_is_valid_base(const char *base, const size_t base_length)
{
	size_t	used_position;
	char	used_characters[base_length + 1];

	if (base_length == 0 || base_length == 1)
		return (false);
	used_characters[0] = '\0';
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return (false);
		used_position = 0;
		while (used_characters[used_position] != '\0')
		{
			if (used_characters[used_position] == *base)
				return (false);
			used_position++;
		}
		used_characters[used_position] = *base;
		used_characters[used_position + 1] = '\0';
		base++;
	}
	return (true);
}
