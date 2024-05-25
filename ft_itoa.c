/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:23:47 by youchiya          #+#    #+#             */
/*   Updated: 2024/05/08 22:34:43 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_sub(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		sign;

	len = ft_itoa_sub(n);
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n > 0)
		n *= -1;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	while (--len >= sign)
	{
		result[len] = -1 * (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		result[0] = '-';
	return (result);
}
