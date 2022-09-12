/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:33 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/12 20:32:23 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		lines;
	int		fd;
	char	*str;

	str = NULL;
	fd = 0;
	fd = open ("teste.txt", O_RDONLY);
	lines = 10;
	if (fd < 0)
	{
		printf("Erro ao abrir arquivo.");
		return (0);
	}
	while (lines--)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
}
