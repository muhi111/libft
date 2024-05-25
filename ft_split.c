/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchiya <youchiya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:15:58 by youchiya          #+#    #+#             */
/*   Updated: 2024/05/08 22:36:09 by youchiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_count(char const *str, char c)
{
	size_t	count;
	size_t	i;
	int		flag;

	count = 0;
	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (flag == 0)
			{
				count++;
				flag = 1;
			}
		}
		else
			flag = 0;
		i++;
	}
	if (flag == 0)
		count++;
	return (count);
}

static char	*ft_strndup(char const *src, int n, char **dest)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	*dest = result;
	return (result);
}

static char	**free_split(char **result, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char	**ft_split_sub(char const *str, char c, char **result)
{
	int		i;
	int		j;
	int		prev;

	prev = -1;
	i = -1;
	j = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
		{
			if (i - prev - 1 > 0)
				if (ft_strndup(str + prev + 1, i - prev - 1,
						&result[++j]) == NULL)
					return (free_split(result, j));
			prev = i;
		}
	}
	if (i - prev - 1 > 0)
		if (ft_strndup(str + prev + 1, i - prev - 1, &result[++j]) == NULL)
			return (free_split(result, j));
	result[++j] = NULL;
	return (result);
}

char	**ft_split(char const *str, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (split_count(str, c) + 1));
	if (result == NULL)
		return (NULL);
	if (ft_split_sub(str, c, result) == NULL)
		return (NULL);
	return (result);
}
