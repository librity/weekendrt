# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2021/03/26 16:57:59 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCE: https://github.com/marc-q/libbmp

NAME = example.out

CC = gcc
CC_FLAGS = -Wall -Wextra -O2

SOURCE_FILES = libbmp.c example.c

all: $(SOURCE_FILES)
	$(CC) $(CC_FLAGS) -o $(NAME) $(SOURCE_FILES) $(LIBS)

example: all
	./$(NAME)

clean:
	rm $(NAME)
	rm *.bmp
