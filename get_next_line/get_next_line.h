/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:35:14 by mhaksal           #+#    #+#             */
/*   Updated: 2022/02/28 09:37:45 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	ft_strlcpy2(char *dest, const char *src, size_t size);
int		ft_strlen2(const char *s);
char	*ft_strdup2(const char *str);
void	ft_bzero2(void *s, size_t n);
void	*ft_calloc2(size_t count, size_t size);
char	*ft_strjoin2(char *left_str, char *buff);
size_t	ft_strlcat2(char *dst, const char *src, size_t dstsize);
int		f_strchck2(char *s, char c);

#endif
