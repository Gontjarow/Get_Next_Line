/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:14:44 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/04 15:37:55 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define ABS(value) (((value) < 0) ? -(value) : (value))
# define TRUE (1)
# define FALSE (0)

/*
** Memory free
*/
void	ft_memdel(void **ptr);
void	ft_strdel(char **str);

/*
** Memory allocation
*/
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *str);
char	*ft_strsub(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *dst, const char *str);
char	*ft_strmap(const char *str, char (*f)(char));
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char	*ft_strtrim(const char *str);
char	**ft_strsplit(const char *str, char c);
int		*ft_range(int min, int max);
char	*ft_itoa(int nbr);

/*
** Memory modify, no allocation
*/
void	*ft_memset(void *dst, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);

/*
** Memory checking
*/
void	*ft_memchr(const void *dst, int c, size_t n);
int		ft_memcmp(const void *dst, const void *src, size_t n);

/*
** Standard output
*/
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
void	ft_putstrn(const char *str, size_t n);
void	ft_putstrn_nulls(const char *str, const char c, size_t n);
void	ft_print2dstr(char **array, int count);

/*
** File output
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putendl_fd(const char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);

/*
** Char checking
*/
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isspace(int c);
int		ft_atoi(const char *str);

/*
** String checking
*/
size_t	ft_strclen(const char *str, int c);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strequ(const char *str1, const char *str2);
int		ft_strnequ(const char *str1, const char *str2, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/*
** String modify, no allocation
*/
void	ft_strclr(char *str);
void	ft_bzero(void *dst, size_t n);
char	*ft_strcpy(char *dst, const char *str);
char	*ft_strncpy(char *dst, const char *str, size_t len);
size_t	ft_strlcpy(char *dst, const char *str, size_t n);
char	*ft_strcat(char *dst, const char *str);
char	*ft_strncat(char *dst, const char *str, size_t n);
size_t	ft_strlcat(char *dst, const char *str, size_t dstsize);
void	ft_striter(char *str, void (*func)(char *));
void	ft_striteri(char *str, void (*func)(unsigned int, char *));
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_strrev(char *str);

#endif
