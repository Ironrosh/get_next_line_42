/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:12:45 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/27 18:05:58 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static int		temp_function_one(int i, char *temp)
{
	ft_strdel(&temp);
	if (i == -1)
		return (i);
	return (0);
}

static void		temp_function_two(char *fds, char ***line)
{
	int				test;

	test = ft_strchr(fds, '\n') > 0;
	if (test)
		**line = ft_strsub(fds, 0, ft_strchr(fds, '\0') - fds);
	else
		**line = ft_strdup(fds);
	*fds = *ft_strsub(fds, (unsigned int)(ft_strlen(**line) + test),\
		(ft_strlen(fds) - (ft_strlen(**line) + test)));
}*/

int				get_next_line(const int fd, char **line)
{
	static char		*fds[10000];
	char			buff[BUFF_SIZE + 1];
	int				i;
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
	/*if ((i == -1 || !*(temp = fds[fd])))
		return (temp_function_one(i, temp));
	temp_function_two(fds[fd], &line);
	ft_strdel(&temp);*/
	return (1);
}
