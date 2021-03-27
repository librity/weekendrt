/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libppm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:16:08 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 17:50:38 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPPM_H
# define LIBPPM_H

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void *ft_memset(void *s, int c, size_t n);
static void gpassos_ft_putnbr_fd_p(char numeros[40], int fd);
void gpassos_ft_putnbr_fd(int n, int fd);
void put_header(int image_width, int image_height, int fd);
void put_pixel(int red_int, int green_int, int blue_int, int fd);

#endif
