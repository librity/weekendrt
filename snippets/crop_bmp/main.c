/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:23:29 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 15:43:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SOURCE: https://codereview.stackexchange.com/questions/196084/read-and-write-bmp-file-in-c

// gcc *.c && ./a.out

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

/*
 * Close file and release memory.
 */
static void clean_up(FILE *fp, t_bmp_image *image, char **error)
{
	if (fp != NULL)
	{
		fclose(fp);
	}
	free_bmp(image);
	free(*error);
}

/*
 * Print error message and clean up resources.
 */
static void handle_error(char **error, FILE *fp, t_bmp_image *image)
{
	fprintf(stderr, "ERROR: %s\n", *error);
	clean_up(fp, image, error);

	exit(EXIT_FAILURE);
}

/*
 * Open file. In case of error, print message and exit.
 */
static FILE *open_file(const char *filename, const char *mode)
{
	FILE *fp = fopen(filename, mode);
	if (fp == NULL)
	{
		fprintf(stderr, "Could not open file %s", filename);

		exit(EXIT_FAILURE);
	}

	return fp;
}

static t_bmp_image *read_image(const char *filename, char **error)
{
	FILE *input_ptr = open_file(filename, "rb");

	t_bmp_image *image = read_bmp(input_ptr, error);
	if (*error != NULL)
	{
		handle_error(error, input_ptr, image);
	}
	fclose(input_ptr);

	return image;
}

static void write_image(const char *filename, t_bmp_image *image, char **error)
{
	FILE *output_ptr = open_file(filename, "wb");

	if (!write_bmp(output_ptr, image, error))
	{
		handle_error(error, output_ptr, image);
	}
	fclose(output_ptr);
}

int main(void)
{
	char *error = NULL;
	t_bmp_image *image = read_image("6x6_24bit.bmp", &error);
	write_image("copy.bmp", image, &error);
	t_bmp_image *crop_image = crop_bmp(image, 2, 3, 4, 2, &error);
	write_image("crop.bmp", crop_image, &error);

	bool is_valid = check_bmp_header(&crop_image->header, fopen("crop.bmp", "rb"));

	clean_up(NULL, image, &error);
	clean_up(NULL, crop_image, &error);

	return EXIT_SUCCESS;
}
