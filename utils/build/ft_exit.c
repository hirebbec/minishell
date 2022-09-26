/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:08:43 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 16:40:06 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	perfect_atoi(char *str, int *check)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			(*check) = -1;
			return (-1);
		}
		i++;
	}
	return (ft_atoi(str));
}

int	ft_exit(char **cmds)
{
	int	check;
	int	status;

	check = 1;
	printf("exit\n");
	if (!cmds[1])
		exit(g_status);
	status = perfect_atoi(cmds[1], &check);
	if (check == -1)
	{
		ft_printf(2, GREEN "MiniShell: " WHITE);
		ft_printf(2, "exit: %s: numeric argument required\n", cmds[1]);
		exit(255);
	}
	if (status < 0)
		exit ((status % 256) + 256);
	else
		exit(status % 256);
	return (0);
}
