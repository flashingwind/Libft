/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muiida <muiida@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:06:24 by muiida            #+#    #+#             */
/*   Updated: 2024/10/31 01:23:32 by muiida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// libc Functions
// ctype.h
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

int					ft_tolower(int c);
int					ft_toupper(int c);

// string.h
// strlen() 関数は文字列 s の長さを計算する。 このとき、終端ヌルバイト ('\0') は計算に含まれない。
size_t				ft_strlen(const char *s);
// memset() は s で示されるメモリ領域の先頭から n バイトを c で埋める。memset()は s へのポインタを返す。
void				*ft_memset(void *p, int c, size_t len);
//   bzero() 関数は バイト列 s から始まる領域の先頭 n バイトを 数値ゼロ (値が '\0' のバイト) で埋める。
void				ft_bzero(void *s, size_t n);

// memcpy() はメモリー領域 src の先頭 n バイトを メモリー領域 dest
// にコピーする。 コピー元の領域とコピー先の領域が重なってはならない。重なっている場合は memmove(3)を使うこと。
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

// bsd/string.h
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

// strnstr() 関数は、len 文字より少ない文字列 big の中で、
// ヌル文字で終了する文字列 little が最初に出現する位置を探します。
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

char				*ft_strdup(const char *s);

// stdlib.h
int					ft_atoi(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);

// Additional functions
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// Bonus part
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif