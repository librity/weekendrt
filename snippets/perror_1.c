/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:35:01 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 03:36:06 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc perror_1.c && ./a.out

#include <stdio.h>

int main()
{
	FILE *fp;

	/* first rename if there is any file */
	rename("file.txt", "newfile.txt");

	/* now let's try to open same file */
	fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		perror("Error: ");
		return (-1);
	}
	fclose(fp);

	return (0);
}
