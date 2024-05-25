/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 06:58:46 by youchiya          #+#    #+#             */
/*   Updated: 2024/05/08 22:33:45 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size != 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}
