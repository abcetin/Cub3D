/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:35:11 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/01 12:27:37 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	if (!*s && c == '\0')
		return ((char *)s);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		if (s[i + 1] == '\0' && c == '\0')
			return ((char *)s + i + 1);
		i++;
	}
	return (NULL);
}

static char	*_fore(char *ptr)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	tmp = malloc(i + 1);
	ft_strlcpy2(tmp, ptr, i + 1);
	return (tmp);
}

static char	*_after(char *ptr)
{
	char	*tmp;
	int		i;

	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i + 1] && ptr[i])
	{
		tmp = ft_strdup2(&ptr[i + 1]);
		free(ptr);
		return (tmp);
	}
	if (ptr)
		free(ptr);
	return (NULL);
}

static char	*_save(int fd, char	*ptr)
{
	char	*buffer;
	int		a;

	buffer = malloc(BUFFER_SIZE + 1);
	a = read(fd, buffer, BUFFER_SIZE);
	while (a > 0)
	{
		buffer[a] = '\0';
		ptr = ft_strjoin2(ptr, buffer);
		if (ft_strchr2(ptr, '\n'))
		{
			free(buffer);
			return (ptr);
		}
		a = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (ptr)
		return (ptr);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*tmp;

	if (!ptr || !ft_strchr2(ptr, '\n'))
		ptr = _save(fd, ptr);
	if (!ptr)
		return (NULL);
	tmp = _fore(ptr);
	ptr = _after(ptr);
	return (tmp);
}
