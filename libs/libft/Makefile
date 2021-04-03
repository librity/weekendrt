# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 21:58:14 by lpaulo-m          #+#    #+#              #
#    Updated: 2021/04/03 15:49:19 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs
TESTS_PATH = ./tests

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
CC_DEBUG_FLAGS = -g

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

HEADER_FILE = ft_printf.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES = unless.c \
	ft_abs.c ft_abs_i.c ft_abs_f.c ft_abs_d.c \
	\
	ft_min_d.c ft_max_d.c ft_clamp_d.c \
	\
	ft_swap.c ft_swap_i.c \
	\
	ft_div_mod.c ft_div_mod_i.c \
	\
	ft_sqrt.c ft_sqrt_i.c ft_pow.c ft_pow_i.c ft_fibonacci.c ft_factorial.c \
	\
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c \
	\
	ft_strlen.c ft_strcpy.c ft_strdel.c ft_strnchr.c \
	\
	ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strnstr.c ft_strncmp.c \
	\
	ft_atoi.c ft_atoui.c ft_atoui_strict.c \
	\
	ft_isdigit.c ft_is_whitespace.c ft_is_plus_or_minus.c \
	ft_is_decimal_char.c ft_isupper.c ft_islower.c ft_isalpha.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c \
	\
	ft_toupper.c ft_tolower.c \
	\
	ft_calloc.c ft_strdup.c \
	\
	ft_substr.c ft_strtrim.c ft_split.c ft_strmapi.c \
	\
	ft_strjoin.c ft_strjoin_and_free.c ft_strjoin_and_free_free.c \
	ft_strjoin_and_del.c ft_strjoin_and_del_del.c \
	\
	ft_itoa.c ft_i_to_buffer.c \
	\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	\
	ft_putchar.c ft_putstr.c ft_putstr_up_to.c ft_putendl.c \
	\
	ft_is_valid_base.c ft_aux_handle_minus_sign_li.c \
	\
	ft_putnbr.c ft_putnbr_i.c ft_putnbr_ui.c ft_putnbr_ul.c ft_putnbr_li.c \
	\
	ft_putnbr_base.c ft_putnbr_base_i.c ft_putnbr_base_ui.c \
	ft_putnbr_base_ul.c ft_putnbr_base_li.c \
	\
	ft_puthex_uppercase.c ft_puthex_downcase.c \
	\
	ft_count_digits.c ft_count_digits_i.c ft_count_digits_i.c \
	ft_count_digits_ui.c ft_count_digits_ul.c \
	\
	ft_count_digits_hex_ui.c ft_count_digits_hex_ul.c \
	\
	ft_count_chars_i.c \
	\
	ft_skip_digits.c ft_skip_number.c \
	\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	\
	ft_get_next_line.c
SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

EXAMPLE_MAIN = example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

all: $(NAME)

$(NAME): $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(SAFE_MAKEDIR) $(OBJECTS_PATH)
	$(CC) $(CC_FLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

example: $(NAME)
	$(CC) $(CC_DEBUG_FLAGS) -I $(INCLUDES_PATH) $(EXAMPLE_MAIN) $(NAME)
	$(EXECUTE_EXAMPLE)

test:
	$(MAKE_EXTERNAL) $(TESTS_PATH)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

test_clean:
	$(MAKE_EXTERNAL) $(TESTS_PATH) fclean

re: fclean all

norm:
	norminette $(INCLUDES_PATH)
	@echo ----------------------
	norminette $(SOURCES_PATH)

git:
	git add -A
	git commit -m "update"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

.PHONY: all example test re clean fclean example_clean test_clean norme git gitm
