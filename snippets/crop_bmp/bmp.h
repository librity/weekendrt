/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:23:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 16:23:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SOURCE: https://codereview.stackexchange.com/questions/196084/read-and-write-bmp-file-in-c

#ifndef BMP_H
#define BMP_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define BMP_HEADER_SIZE 54
#define DIB_HEADER_SIZE 40

#define MAGIC_VALUE 0x4D42
#define NUM_PLANE 1
#define COMPRESSION 0
#define NUM_COLORS 0
#define IMPORTANT_COLORS 0
#define BITS_PER_PIXEL 24
#define BITS_PER_BYTE 8

#pragma pack(push)
#pragma pack(1)

typedef struct
{
	uint16_t type;
	uint32_t size;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t offset;
	uint32_t dib_header_size;
	int32_t width_px;
	int32_t height_px;
	uint16_t num_planes;
	uint16_t bits_per_pixel;
	uint32_t compression;
	uint32_t image_size_bytes;
	int32_t x_resolution_ppm;
	int32_t y_resolution_ppm;
	uint32_t num_colors;
	uint32_t important_colors;
} t_bmp_header;

#pragma pack(pop)

typedef struct
{
	t_bmp_header header;
	unsigned char *data;
} t_bmp_image;

t_bmp_image *read_bmp(FILE *fp, char **error);
bool check_bmp_header(t_bmp_header *bmp_header, FILE *fp);
bool write_bmp(FILE *fp, t_bmp_image *image, char **error);
void free_bmp(t_bmp_image *image);
t_bmp_image *crop_bmp(t_bmp_image *image, int x, int y, int w, int h, char **error);

#endif
