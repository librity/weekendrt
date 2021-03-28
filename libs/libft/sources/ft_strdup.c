/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/25 20:02:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Creates an allocated string with the same chars of s.
*/

char	*ft_strdup(const char *s)
{
	size_t	original_size;
	char	*new_string;

	original_size = ft_strlen(s) + 1;
	new_string = malloc((original_size) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_memcpy(new_string, s, original_size);
	return (new_string);
}
