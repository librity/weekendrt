/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:58:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/26 02:43:14 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/resource.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define MAX_FILE_DESCRIPTOR RLIMIT_NOFILE

# define GNL_FOUND_LINEBREAK 1
# define GNL_FOUND_EOF 0
# define GNL_ERROR -1

# define DECIMAL_BASE "0123456789"
# define DOWNCASE_HEX_BASE "0123456789abcdef"
# define UPPERCASE_HEX_BASE "0123456789ABCDEF"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

bool				unless(bool condition);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, char *src);
void				ft_strdel(char **delete_me);
char				*ft_strnchr(const char *s, int c, unsigned int limit);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
								const char *needle,
								size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *number_pointer);
unsigned int		ft_atoui(const char *number_pointer);
unsigned int		ft_atoui_strict(const char *number_pointer);

bool				ft_isdigit(int c);
bool				ft_is_whitespace(char character);
bool				ft_is_plus_or_minus(char character);
bool				ft_is_decimal_char(char character);
bool				ft_isupper(int c);
bool				ft_islower(int c);
bool				ft_isalpha(int c);
bool				ft_isalnum(int c);
bool				ft_isascii(int c);
bool				ft_isprint(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_and_free(char *free_me,
											char const *dont_free_me);
char				*ft_strjoin_and_free_free(char *free_me, char *free_me_too);
char				*ft_strjoin_and_del(char *delete_me,
										char const *dont_delete_me);
char				*ft_strjoin_and_del_del(char *delete_me,
											char *delete_me_too);

char				*ft_itoa(int n);
unsigned int		ft_i_to_buffer(int n, char *buffer);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putstr_up_to(char *s, size_t up_to);
void				ft_putendl(char *s);

bool				ft_is_valid_base(const char *base,
										const size_t base_length);
void				ft_aux_handle_minus_sign_li(long int *number_pointer);

void				ft_putnbr(int n);
void				ft_putnbr_i(int number);
void				ft_putnbr_ui(unsigned int number);
void				ft_putnbr_ul(unsigned long number);
void				ft_putnbr_li(long int number);

void				ft_putnbr_base(int number, char *base);
void				ft_putnbr_base_i(int number, char *base);
void				ft_putnbr_base_ui(unsigned int number, const char *base);
void				ft_putnbr_base_ul(unsigned long number, const char *base);
void				ft_putnbr_base_li(long int number, const char *base);

void				ft_puthex_uppercase(unsigned int number);
void				ft_puthex_downcase(unsigned int number);

unsigned int		ft_count_digits(int number);
unsigned int		ft_count_digits_i(int number);
unsigned int		ft_count_digits_i(int number);
unsigned int		ft_count_digits_ui(unsigned int number);
unsigned int		ft_count_digits_ul(unsigned long number);

unsigned int		ft_count_digits_hex_ui(unsigned int number);
unsigned int		ft_count_digits_hex_ul(unsigned long number);

unsigned int		ft_count_chars_i(int number);

char				*ft_skip_digits(char *digits);
char				*ft_skip_number(char *digits);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
								void *(*f)(void *),
								void (*del)(void *));

int					ft_get_next_line(int fd, char **line);

#endif
