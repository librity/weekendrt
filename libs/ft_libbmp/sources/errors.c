/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:17:24 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/04 13:14:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libbmp.h>

static void	print_error(char *message)
{
	write(1, "\033[31;1;4mERROR: ", 17);
	while (*message)
		write(1, message++, 1);
	write(1, "\033[0m", 4);
	write(1, "\n", 1);
}

static char	*fetch_error_message(t_bitmap_error code)
{
	static char	*error_messages[GENERIC_BITMAP_ERROR] = {
		"Error creating file.",
		"Header didn't initialize properly.",
		"Unable to allocate required memory.",
		"Generic bitmap error.",
	};

	return (error_messages[code]);
}

void		bm_kill(t_bitmap_error code)
{
	print_error(fetch_error_message(code));
	exit(EXIT_FAILURE);
}
