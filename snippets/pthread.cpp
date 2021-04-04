/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 03:55:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/04/04 03:58:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
using namespace std;
#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("Hello World! Thread ID, %d\n", tid);
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int rc;
	int i;
	for (i = 0; i < NUM_THREADS; i++)
	{
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
		if (rc)
		{
			printf("Error:unable to create thread, %d\n", rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
