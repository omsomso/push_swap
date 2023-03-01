/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:07:13 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 00:49:23 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	gnl_find_char(const char *s, int c, int n)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = (unsigned char) c;
	while (i == -1 || s[i] || i < n)
	{
		i++;
		if (s[i] == tmp)
			return (i);
	}
	return (0);
}
