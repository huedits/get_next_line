/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:01:41 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/07 02:40:05 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*aux;
	char		*line;
	ssize_t		i;
	
	line = (char *) ft_calloc(1,1);
	buffer = (char *) malloc (BUFFER_SIZE + 1);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (!aux)
			aux = line;
		line = ft_strjoin(aux, ft_substr(buffer, 0, i + 1));
		free(aux);
		aux = NULL;
		if (buffer[i] == '\n')
		{
			aux = ft_strdup(buffer + (i + 1));
			free(buffer);
			return (line);
		}
		else
			ft_bzero(buffer, ft_strlen(buffer));
	}
	if (*aux)
	{
		line = ft_strdup(aux);
		free(aux);
		return (line);
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	total_size;

	if (dstsize > ft_strlen(dst))
	{
		total_size = ft_strlen(dst) + ft_strlen(src);
		while (*dst)
		{
			dst++;
			dstsize--;
		}
		i = 0;
		while (i < (dstsize - 1) && src && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		total_size = ft_strlen(src) + dstsize;
	}
	return (total_size);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc ((ft_strlen(s1) + 1) * sizeof (char));
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}