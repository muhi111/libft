/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:39:37 by youchiya          #+#    #+#             */
/*   Updated: 2024/05/08 14:44:55 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	j;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	j = n % 10;
	if (n >= 10)
	{
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	ft_putchar_fd(j + '0', fd);
}
