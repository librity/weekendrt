/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libppm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:37:04 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 17:37:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libppm.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *pointerator;
	unsigned char casted_char;

	pointerator = s;
	casted_char = (unsigned char)c;
	while (n--)
	{
		*pointerator = casted_char;
		pointerator++;
	}
	return (s);
}

static void gpassos_ft_putnbr_fd_p(char numeros[40], int fd)
{
	int i;

	i = 0;
	while (i < 40)
	{
		if (numeros[i] != -1)
			ft_putchar_fd(numeros[i] + '0', fd);
		i++;
	}
}

void gpassos_ft_putnbr_fd(int n, int fd)
{
	char numeros[40];
	int i;

	if (n == -2147483648LL)
	{
		ft_putstr_fd("-2147483648", fd);
		return;
	}
	ft_memset(numeros, -1, 40);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	i = 39;
	while (n > 9)
	{
		numeros[i] = (n % 10);
		n = (n / 10);
		i--;
	}
	numeros[i] = n;
	gpassos_ft_putnbr_fd_p(numeros, fd);
}

void put_header(int image_width, int image_height, int fd)
{
	ft_putstr_fd("P3\n", fd);
	gpassos_ft_putnbr_fd(image_width, fd);
	ft_putstr_fd(" ", fd);
	gpassos_ft_putnbr_fd(image_height, fd);
	ft_putstr_fd("\n255\n", fd);
}

void put_pixel(int red_int, int green_int, int blue_int, int fd)
{
	gpassos_ft_putnbr_fd(red_int, fd);
	ft_putstr_fd(" ", fd);
	gpassos_ft_putnbr_fd(green_int, fd);
	ft_putstr_fd(" ", fd);
	gpassos_ft_putnbr_fd(blue_int, fd);
	ft_putstr_fd("\n", fd);
}
