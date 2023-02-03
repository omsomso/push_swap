/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:01:11 by kpawlows          #+#    #+#             */
/*   Updated: 2022/11/12 07:53:20 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	slen;

	slen = ft_strlen(s);
	write(fd, s, slen);
}

/*int	main(void)
{
	ft_putstr_fd("eyo", 1);
	write(1, "\n", 1);
	return (0);
}*/
