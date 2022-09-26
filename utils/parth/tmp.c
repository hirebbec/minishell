/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:02:02 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 16:40:35 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tmp11(char **cmd, char *str, int *i)
{
	if (str[(*i) + 1] == '$')
	{
		(*cmd) = ft_charjoin_free((*cmd), '$');
		(*i) = (*i) + 2;
	}
	else
		(*i)++;
}

int	ft_tmp12(void)
{
	ft_printf(2, GREEN "MiniShell: " \
		WHITE "syntax error unexpected token `|'\n");
	return (-1);
}

void	ft_temp2(int *j, char *c, int *flag, char *input)
{
	while (input[(*j)])
	{
		if (((*c) == 39 && input[(*j)] == 39) || ((*c) == 34 \
		&& input[(*j)] == 34 && input[(*j) - 1] != 92))
		{
			(*flag) = 0;
			break ;
		}
		(*j)++;
	}
}

int	tmp_tmp(char *tmp)
{
	free(tmp);
	g_status = 0;
	return (0);
}
