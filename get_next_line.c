/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:12:45 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/23 17:18:27 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*fds[10000];
	char			buff[BUFF_SIZE + 1];
	char			i;
	char			*temp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	while (!ft_strchr(fds[fd], '\n') && (i = read(fd, buff, BUFF_SIZE) > 0))
	{
		buff[i] = '\0';
		temp = fds[fd];
		fds[fd] = ft_strjoin(fds[fd], buff);
		free(&temp);
	}
	
}
