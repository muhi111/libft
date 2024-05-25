/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:59:29 by youchiya          #+#    #+#             */
/*   Updated: 2024/04/23 09:16:48 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)(s + len));
	return (NULL);
}
