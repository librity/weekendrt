/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:54:30 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/25 20:02:49 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_and_free_free(char *free_me, char *free_me_too)
{
	size_t	total_size;
	size_t	free_me_size;
	char	*new_string;

	free_me_size = ft_strlen(free_me) + 1;
	total_size = free_me_size + ft_strlen(free_me_too);
	new_string = malloc(total_size * sizeof(char));
	if (new_string == NULL)
	{
		free(free_me);
		free(free_me_too);
		return (NULL);
	}
	ft_strcpy(new_string, free_me);
	ft_strlcat(new_string, free_me_too, total_size);
	free(free_me);
	free(free_me_too);
	return (new_string);
}
