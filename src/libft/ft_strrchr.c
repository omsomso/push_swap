/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:24:14 by kpawlows          #+#    #+#             */
/*   Updated: 2022/11/13 21:47:01 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				slen;
	unsigned char	tmp;

	slen = ft_strlen(s);
	tmp = (unsigned char) c;
	while (slen >= 0)
	{
		if (s[slen] == tmp)
			return ((char *) &s[slen]);
		slen--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str1[] = "okjjkofhgwo";
	int		c = 1024;
	int		d = 'o';
	
	printf("%s\n%s\n", ft_strrchr(str1, c), strrchr(str1, c));
	printf("%s\n%s\n", ft_strrchr(str1, d), strrchr(str1, d));
	c = '\0';
	printf("%s\n%s\n", ft_strrchr(str1, c), strrchr(str1, c));
	return (0);
}*/