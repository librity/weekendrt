/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:40:25 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/03 12:48:02 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void fun()
{
	printf("fun() starts \n");
	printf("Press enter to stop fun \n");
	while (true)
	{
		if (getchar())
			break;
	}
	printf("fun() ends \n");
}

int main()
{
	clock_t time;
	time = clock();
	fun();
	time = clock() - time;
	double elapsed_time = ((double)time) / CLOCKS_PER_SEC; // in seconds

	printf("fun() took %f seconds to execute \n", elapsed_time);
	return 0;
}
