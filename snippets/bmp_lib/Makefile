# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2021/03/26 17:40:30 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCE: https://github.com/marc-q/libbmp

NAME = checkerboard.out

CC = gcc
CC_FLAGS = -Wall -Wextra -O2

SOURCE_FILES = libbmp.c checkerboard.c

all: $(SOURCE_FILES)
	$(CC) $(CC_FLAGS) -o $(NAME) $(SOURCE_FILES) $(LIBS)

checkerboard: all
	./$(NAME)
	ffplay checkerboard.bmp

clean:
	rm $(NAME)
	rm *.bmp
