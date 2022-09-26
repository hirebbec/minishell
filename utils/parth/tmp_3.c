/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:33:28 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/06 22:04:32 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		red_tmp(void);
int		red_tmp2(void);
int		red_tmp3(char *name, char *before, char *after);
char	*red_tmp4(t_shell *shell, int i, char **name, char *before);
void	red_tmp5(int *start, int *i, t_shell *shell, char **name);
void	red_tmp6(int *i, int *start, t_shell *shell, char **name);
void	red_tmp7(int *i, int *start, t_shell *shell, char **name);

void	red_tmp6(int *i, int *start, t_shell *shell, char **name)
{
	(*i)++;
	(*start) = (*i);
	while (shell->call->cmd[(*i)] != ONE \
		&& shell->call->cmd[(*i) - 1] != '\\' && shell->call->cmd[(*i)])
		(*i)++;
	(*name) = ft_substr(shell->call->cmd, (*start), (*i) - (*start));
}

void	red_tmp7(int *i, int *start, t_shell *shell, char **name)
{
	(*i)++;
	(*start) = (*i);
	while (shell->call->cmd[(*i)] != ONE && shell->call->cmd[(*i)])
		(*i)++;
	(*name) = ft_substr(shell->call->cmd, (*start), (*i) - (*start));
}

void	red_tmp8(int *i, int *start, t_shell *shell, char **name)
{
	if (shell->call->cmd[(*i)] == ONE)
		red_tmp7(i, start, shell, name);
	else if (shell->call->cmd[(*i)] == TWO)
		red_tmp6(i, start, shell, name);
	else
		red_tmp5(start, i, shell, name);
}

void	red_tmp9(int *status, int *i)
{
	(*i)++;
	(*status) = 2;
}

int	red_tmp10(void)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, "syntax error near unexpected token `>'");
	return (-1);
}
