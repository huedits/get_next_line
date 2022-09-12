/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:01:41 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:12 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;
	char		*buffer;
	ssize_t		i;
	ssize_t		chars_read;

	i = 0;
	chars_read = BUFFER_SIZE;
	buffer = NULL;
	line = NULL;
	if (!aux)
		aux = (char *) ft_calloc(1, 1);
	while (chars_read > 0)
	{
		while (aux[i] != '\n' && aux[i])
			i++;
		if (aux[i] == '\n')
		{
			line = aux;
			aux = ft_substr(line, i + 1, ft_strlen(line + i + 1));
			ft_bzero(line + i + 1, ft_strlen(line + i + 1));
			return (line);
		}
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(aux, buffer);
		free(aux);
		aux = line;
		free(buffer);
	}
	if (!*aux)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	line = aux;
	aux = NULL;
	return (line);
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
