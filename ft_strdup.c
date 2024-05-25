/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 07:01:59 by youchiya          #+#    #+#             */
/*   Updated: 2024/04/23 07:02:27 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s, len);
	result[len] = '\0';
	return (result);
}
