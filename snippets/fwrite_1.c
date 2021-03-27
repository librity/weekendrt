/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwrite_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 19:49:07 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/27 03:36:23 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc fwrite_1.c && ./a.out

#include <stdio.h>
#include <stdlib.h>

struct employee
{
	char name[50];
	char designation[50];
	int age;
	float salary
} employee;

int main()
{
	int n, i, chars;
	FILE *fp;

	fp = fopen("employee.txt", "wb");

	if (fp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	printf("Testing fwrite() function: \n\n");

	printf("Enter the number of records you want to enter: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nEnter details of employee %d \n", i + 1);

		fflush(stdin);

		printf("Name: ");
		gets(employee.name);

		printf("Designation: ");
		gets(employee.designation);

		printf("Age: ");
		scanf("%d", &employee.age);

		printf("Salary: ");
		scanf("%f", &employee.salary);

		chars = fwrite(&employee, sizeof(employee), 1, fp);
		printf("Number of items written to the file: %d\n", chars);
	}

	fclose(fp);
	return 0;
}
