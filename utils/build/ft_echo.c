/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:03:24 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/18 21:49:46 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char **cmds, int i)
{
	int	flag;

	g_status = 0;
	flag = 0;
	if (!cmds[i])
	{
		printf("\n");
		return (0);
	}
	while (!ft_strncmp(cmds[i], "-n", 2) && ft_len_dif(cmds[i], "-n") == 0)
	{
		i++;
		if (!cmds[i])
			return (0);
	}
	flag = i - 1;
	while (cmds[i])
	{
		ft_printf(1, "%s ", cmds[i]);
		i++;
	}
	if (!flag)
		printf("\n");
	return (0);
}
