/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:12:45 by mhorpe            #+#    #+#             */
/*   Updated: 2019/10/03 13:07:17 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static int		temp_function_one(int i)
{
	if (i == -1)
		return (-1);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*c[2147483647];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		i;
	int			endl;

	if (fd < 0 || (!c[fd] && !(c[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(c[fd], '\n') && (i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		tmp = c[fd];
		c[fd] = ft_strjoin(c[fd], buffer);
		ft_strdel(&tmp);
	}
	if (i == -1 || !*(tmp = c[fd]))
		return (temp_function_one(i));
	if ((endl = (ft_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, ft_strchr(c[fd], '\n') - c[fd]);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&tmp);
	return (!(!c[fd] && !ft_strlen(*line)));
}
