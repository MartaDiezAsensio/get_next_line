/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:20:24 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/31 14:22:55 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int 	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error when executing open");
		return (-1);
	}

	int i = 0;
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		i++;
	}
	
	free(line);
	close(fd);

	return (0);
}