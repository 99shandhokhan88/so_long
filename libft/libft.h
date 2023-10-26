#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>


int		        ft_print_char(int c);
int		        ft_print_str(char *str);
int		        ft_print_num(int nb);
int		        ft_convert_add(unsigned long nb, char *s);
int		        ft_print_point(unsigned long nb, char *s);
int		        ft_print_unsign(unsigned int nb);
int		        ft_print_hex(unsigned int nb, char *s);
int		        ft_print_only(int c);
int		        ft_check_type(va_list args, const char str);
int		        ft_printf(const char *str, ...);
char	        *ft_strchr(const char *str, int ch);
char	        *ft_strdup(char *src);
char	        *ft_strjoin(char *res, char *temp);
size_t	        ft_strlen(const char *str);
int             ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	        **ft_split(const char *s, char c);
char	        *ft_substr(char const *s, unsigned int start, size_t len);
char	        *ft_write_next_line(char *new_line);
char	        *ft_get_new_line(char *new_line);
char	        *ft_read_new_line(int fd, char *new_line);
char            *get_next_line(int fd);
char            *ft_itoa(int n);

#endif