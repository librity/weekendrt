/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:54:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/25 20:02:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_and_free(char *free_me, char const *dont_free_me)
{
	size_t	total_size;
	size_t	free_me_size;
	char	*new_string;

	free_me_size = ft_strlen(free_me) + 1;
	total_size = free_me_size + ft_strlen(dont_free_me);
	new_string = malloc(total_size * sizeof(char));
	if (new_string == NULL)
	{
		free(free_me);
		return (NULL);
	}
	ft_strcpy(new_string, free_me);
	ft_strlcat(new_string, dont_free_me, total_size);
	free(free_me);
	return (new_string);
}
