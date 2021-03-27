/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fflush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 04:02:37 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 04:03:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program to illustrate flush(stdin)
// This program works as expected only
// in certain compilers like Microsoft
// visual studio.

// gcc fflush.c && ./a.out

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[20];
	int i;
	for (i = 0; i < 2; i++)
	{
		scanf("%[^\n]s", str);
		printf("%s\n", str);

		// used to clear the buffer
		// and accept the next string
		fflush(stdin);
	}
	return 0;
}
