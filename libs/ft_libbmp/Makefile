# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2021/03/26 18:22:50 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Based on: https://github.com/marc-q/libbmp

NAME = example.out

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SOURCE_FILES = ft_libbmp.c example.c

all: $(SOURCE_FILES)
	$(CC) $(CC_FLAGS) -o $(NAME) $(SOURCE_FILES)

example: all
	./$(NAME)
	ffplay hello.bmp

clean:
	rm -f *.bmp
	rm -f $(NAME)
