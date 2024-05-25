/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:16:53 by youchiya          #+#    #+#             */
/*   Updated: 2024/05/08 22:55:57 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	check_over_and_underflow(long result, int sign, int next)
{
	if (sign == 1)
	{
		if (result < -1 * (LONG_MAX / 10))
			return (LONG_MAX);
		else if (result == -1 * (LONG_MAX / 10) && next > LONG_MAX % 10)
			return (LONG_MAX);
	}
	else
	{
		if (result < LONG_MIN / 10)
			return (LONG_MIN);
		else if (result == LONG_MIN / 10 && next > -1 * (LONG_MIN % 10))
			return (LONG_MIN);
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (check_over_and_underflow(result, sign, *nptr - '0') != result)
			return ((int)(check_over_and_underflow(result, sign, *nptr - '0')));
		result = result * 10 - (*nptr - '0');
		nptr++;
	}
	return ((int)(result * (sign * -1)));
}
