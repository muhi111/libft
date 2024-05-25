/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:15:18 by youchiya          #+#    #+#             */
/*   Updated: 2024/05/08 18:27:54 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = -1;
	if (ptr_dest < ptr_src)
	{
		while (++i < n)
			ptr_dest[i] = ptr_src[i];
	}
	else
	{
		while (++i < n)
			ptr_dest[n - i - 1] = ptr_src[n - i - 1];
	}
	return (dest);
}
