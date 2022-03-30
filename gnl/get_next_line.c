/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:47:59 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/22 16:19:45 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*ft_read(int fd, char *save)
{
	int		bytes;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = 0;
		if (!save)
		{
			save = malloc(sizeof(char) * 1);
			save[0] = 0;
		}
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_overload(char *str)
{
	int		a;
	int		b;
	char	*ptr;

	a = 0;
	while (str[a] && str[a] != '\n')
		a++;
	if (!str[a])
	{
		free(str);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (ft_strlen(str) - a + 1));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	a++;
	b = 0;
	while (str[a])
		ptr[b++] = str[a++];
	ptr[b] = 0;
	free(str);
	return (ptr);
}

char	*ft_get_line(char *str)
{
	char	*aux;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	aux = malloc(sizeof(char) * (i + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		aux[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		aux[i] = '\n';
		i++;
	}
	aux[i] = 0;
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_overload(save);
	return (line);
}



