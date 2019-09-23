/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:35:12 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 18:19:04 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	i = 0;
	if (f && s)
	{
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
	}
}
