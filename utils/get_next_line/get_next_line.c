/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:22:56 by hirebbec          #+#    #+#             */
/*   Updated: 2021/11/21 22:22:58 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*read_line(int fd, char	*buf)
{
	int		flag;
	char	*rd_buf;

	flag = 1;
	rd_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!rd_buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && flag)
	{
		flag = read(fd, rd_buf, BUFFER_SIZE);
		if (flag == -1)
		{
			free(rd_buf);
			return (NULL);
		}
		rd_buf[flag] = '\0';
		buf = ft_strjoin_free(buf, rd_buf);
	}
	free(rd_buf);
	return (buf);
}

char	*get_one_line(char	*buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_buf(char	*buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	str = malloc(ft_strlen(buf) - i + 1);
	if (!str)
	{
		free(buf);
		return (NULL);
	}
	i++;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = 0;
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = read_line(fd, buf);
	if (!buf)
		return (NULL);
	line = get_one_line(buf);
	buf = get_buf(buf);
	return (line);
}
