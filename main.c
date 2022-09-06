/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:33 by vimatheu          #+#    #+#             */
/*   Updated: 2022/09/06 20:11:17 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	lines = 10;
	int	fd;
	char	*str;
	
	fd = open ("teste.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erro ao abrir arquivo.");
		return (0);
	}
	while (lines--)
	{
		str = get_next_line(fd);
		if (str)
			printf("%s", str);
	}
}