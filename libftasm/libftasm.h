/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 17:57:44 by cmehay            #+#    #+#             */
/*   Updated: 2015/08/29 17:21:57 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H

int 	ft_isalpha(char c);
int 	ft_isdigit(char c);
int 	ft_isalnum(char c);
int 	ft_isascii(char c);
int 	ft_isprint(char c);
int 	ft_tolower(int c);
int 	ft_toupper(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char    *ft_strcat(char *dest, const char *src);
size_t	ft_strlen(char const *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_puts(const char *s);
char	*ft_strdup(const char *s);
void	ft_cat(int fd);

#endif
