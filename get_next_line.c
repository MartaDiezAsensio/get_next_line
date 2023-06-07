/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:41:35 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/07 20:51:40 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *true_free(char **ptr)
{
	free(ptr);
	*ptr = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_getline(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	//if (!line)
	//	return(true_free(&str));
	str = ft_getmem(str);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer){
		free(str);
		return (NULL);
	}
	bytes = 1;
	while (bytes != 0 && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_getline(char *full_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!full_str[i])
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (full_str[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getmem(char *str)
{
	int		i;
	int		j;
	char	*mem;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	mem = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!mem)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i] != '\0')
		mem[j++] = str[i++];
	mem[j] = '\0';
	free(str);
	return (mem);
}
