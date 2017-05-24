/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:53:21 by jargote           #+#    #+#             */
/*   Updated: 2017/05/23 17:46:11 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define UINT_MAX 4294967295
# define LONG_MIN (-9223372036854775808)
# define LONG_MAX 9223372036854775807
# define ULLONG_MAX 18446744073709551615
# define ULONG_MAX 4294967295
# define SINT_MIN (-32768)
# define SINT_MAX 32767
# define USHRT_MAX 65535
# define CHAR_MIN (-128)
# define CHAR_MAX 127
# define UCHAR_MAX 255

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_memchrlen(char *s, int c, size_t n);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					count_isdigit(char *str);
char				*lowercase(char *str);
char				*strreverse(char *str);
char				*strinconce(char *s, char *str, int count);

void				ft_printstrings(char **arr);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_iswhitespace(char c);
unsigned int		*ctowc(unsigned int ui, int *size);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				putnchar(int n, char c);
void				ft_putuint(unsigned int n);

int					get_next_line(const int fd, char **line);

int					ft_isneg(int n);
int					ft_ispos(int n);
int					ahextoi(char *hex);
int					exponent(int n, int ex);
char				*ft_itoa(int n);
char				*ft_itoabase(int n, int base);
char				*ft_uitoa(unsigned int n);
char				*ft_uitoabase(unsigned int n, int base);
char				*ft_litoa(long int n);
char				*ft_ulitoa(unsigned long int n);
char				*ft_ulitoabase(unsigned long int n, int base);
char				*ft_litoabase(long int n, int base);
char				*ft_sitoabase(short int n, int base);
char				*ft_citoabase(int n, int base);
char				*ft_usitoa(unsigned short int n);
char				*ft_ucitoa(unsigned char n);
char				*ft_imtitoabase(intmax_t n, int base);
char				*ft_uimtitoabase(uintmax_t n, int base);
char				*ft_ustitoabase(size_t n, int base);
char				*ft_usitoabase(unsigned short int n, int base);
char				*ft_ucitoabase(unsigned char n, int base);

#endif
