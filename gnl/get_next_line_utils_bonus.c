/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:48:52 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/16 16:07:53 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	int		b;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!ptr)
		return (NULL);
	a = 0;
	b = 0;
	if (s1)
	{
		while (s1[a] != 0)
		{
			ptr[a] = s1[a];
			a++;
		}
	}
	while (s2[b] != 0)
		ptr[a++] = s2[b++];
	ptr[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen((char *)str);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (&((char *)str)[len]);
		len--;
	}
	return (NULL);
}
