/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:19:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 17:55:54 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <weekendrt.h>

static void	print_error(char *message)
{
	write(1, "\033[31;1;4mERROR: ", 17);
	while (*message)
		write(1, message++, 1);
	write(1, "\033[0m", 4);
	write(1, "\n", 1);
}

static char	*fetch_error_message(t_rt_error code)
{
	static char	*error_messages[GENERIC_RAY_TRACER_ERROR] = {
		"Expected one argument as a filename.",
		"Generic ray tracer error.",
	};

	return (error_messages[code]);
}

void		kill_ray_tracer(t_rt_error code)
{
	print_error(fetch_error_message(code));
	exit(EXIT_FAILURE);
}

void		handle_arguments(int argument_count)
{
	if (argument_count != 2)
		kill_ray_tracer(BAD_ARGUMENTS);
}

