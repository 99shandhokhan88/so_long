/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:30:20 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/31 05:09:35 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_result(char *s)
{
	int		i;
	char	*knife;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\0')
		i++;
	knife = (char *)malloc((i + 2) * sizeof(char));
	if (!knife)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		knife[i] = s[i];
		i++;
	}
	if (s[i] == '\0')
	{
		knife[i] = s[i];
		i++;
	}
	knife[i] = '\0';
	return (knife);
}

char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = (int)read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_next(char *s)
{
	int		i;
	char	*knife;
	int		t;

	i = 0;
	t = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	i++;
	knife = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!knife)
		return (NULL);
	while (s[i] != '\0')
		knife[t++] = s[i++];
	knife[t] = '\0';
	free(s);
	return (knife);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	result = ft_result(stash);
	stash = ft_next(stash);
	return (result);
}
