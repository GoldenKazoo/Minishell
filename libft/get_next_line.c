/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsougoum <vsougoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:51:49 by vsougoum          #+#    #+#             */
/*   Updated: 2024/12/08 18:00:40 by vsougoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_stash_buffer(int fd, char *buffer, char *stash)
{
	int		read_check;
	char	*tmp;

	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (read_check == 0)
			break ;
		if (!stash)
			stash = ft_strdup("");
		buffer[read_check] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*ft_extract_line(char *line)
{
	int		i;
	char	*stash;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!stash)
		return (NULL);
	if (*stash == 0)
	{
		free(stash);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (stash);
}

static void	*ft_init_buffer(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	if (size > 0 && nmemb && nmemb > (UINT_MAX / size))
		return (NULL);
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str_stash;
	char		*buffer;
	char		*line;

	buffer = ft_init_buffer((BUFFER_SIZE + 1), sizeof(char));
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(str_stash);
		buffer = NULL;
		str_stash = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_stash_buffer(fd, buffer, str_stash);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	str_stash = ft_extract_line(line);
	return (line);
}
