/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:22:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/03/28 23:50:08 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MININT		-2147483648
# define MAXINT		2147483647
# define BUFFER_SIZE 1000

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int			ft_tolower(int c);
size_t		ft_strlen(const char *s);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
int			ft_atoi(const char *str);
char		*ft_strrchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		*ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_printf(const char *format, ...);
void		ft_printchar(int c, int *len);
int			ft_printpercent(void);
void		ft_printstr(char *str, int *len);
void		ft_putptr(size_t num, int *len);
void		ft_printptr(size_t ptr, int *len);
void		ft_print_unsigned(unsigned int num, int *len);
void		check_arg(va_list *args, char arg, int *len);
void		ft_printbase(long long int num, char *format, int base, int *len);
void		ft_garbage_collector(void *ptr, int mode, int _exit);
void		*ft_allok(int num, int size, int exit_on_null);
int			ft_doublons_ia(int *tab, int size);
int			ft_isnum(char *str);
int			ft_all_are_num(char **tab);
long int	ft_atoilong(const char *str);
void		ft_putstr(char *s);
void		ft_putchar(char c);
void		ft_putnbr(long int num);
void		ft_putendl(char *s);
void		ft_putnbrendl(long int num);
void		ft_swap(int *a, int *b);
int			ft_strcmp(char *s1, char *s2);
int			ft_indexof_iarr(int *tab, int size, int find);
int			ft_find_min(int *tab, int size);
int			ft_wordcount(const char *tab, char c);
int			ft_find_max(int *tab, int size);
int			ft_find_pivot(int *tab, int size);
void		ft_free_pp(void **tab);
void		*ft_alloc(int count, int size, void (*f)());
char		*ft_get_next_line(int fd);
char		*ft_add_stock(const char *s1, const char *s2);
int			ft_gnl_strchr(const char *str, char c);
void		ft_putnbrendl_fd(long int num, int fd);

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}			t_list;

t_list		*ft_lstnew(void *data);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
