# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2021/03/26 18:06:30 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = example.out

CC = gcc
CC_FLAGS = -Wall -Wextra -O2

SOURCE_FILES = libppm.c example.c

all: $(SOURCE_FILES)
	$(CC) $(CC_FLAGS) -o $(NAME) $(SOURCE_FILES)

example: all
	./$(NAME) hello.ppm
	ffplay hello.ppm

clean:
	rm -f *.ppm
	rm -f $(NAME)
