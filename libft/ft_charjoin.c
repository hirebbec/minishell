/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:52:27 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 18:40:13 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char *str, char c)
{
	int		i;
	char	*res;

	i = ft_strlen(str);
	res = malloc(i + 2);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}

char	*ft_charjoin_free(char *str, char c)
{
	int		i;
	char	*res;

	i = ft_strlen(str);
	res = malloc(i + 2);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	free(str);
	return (res);
}

char	*ft_joinchar_free(char *str, char c)
{
	int		i;
	char	*res;

	i = ft_strlen(str);
	res = malloc(i + 2);
	i = 1;
	res[0] = c;
	while (str[i - 1])
	{
		res[i] = str[i - 1];
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}
