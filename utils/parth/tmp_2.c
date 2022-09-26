/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:09:07 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/06 22:02:31 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	red_tmp(void)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "syntax error near unexpected token `newline'");
	return (-1);
}

int	red_tmp2(void)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "syntax error near unexpected token `<'");
	return (-1);
}

int	red_tmp3(char *name, char *before, char *after)
{
	free(name);
	free(before);
	free(after);
	return (1);
}

char	*red_tmp4(t_shell *shell, int i, char **name, char *before)
{
	char	*after;

	after = ft_substr(shell->call->cmd, i, \
	ft_strlen(shell->call->cmd) - i);
	free((*name));
	(*name) = ft_strjoin(before, after);
	free(shell->call->cmd);
	shell->call->cmd = ft_strdup((*name));
	return (after);
}

void	red_tmp5(int *start, int *i, t_shell *shell, char **name)
{
	(*start) = (*i);
	while (shell->call->cmd[(*i)] != ' ' && shell->call->cmd[(*i)])
		(*i)++;
	(*name) = ft_substr(shell->call->cmd, (*start), (*i) - (*start));
}
