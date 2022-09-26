/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:43:47 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 20:54:10 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		pipe_case(t_shell *shell, int *i);
int		or_tmp(void);
void	delete_this(t_shell *shell);
int		and_case(t_shell *shell, int *i);

void	add_after_or(char *cmd, t_shell *shell)
{
	t_call	*tmp;
	t_call	*new;

	if (shell->call->next == NULL)
		add_back_call(&shell->call, ft_strdup(cmd));
	else
	{
		tmp = shell->call->next;
		new = new_call(cmd);
		new->next = tmp;
		new ->prev = shell->call;
		tmp->prev = new;
		shell->call->next = new;
	}
	shell->call->next->status = 1;
}

int	unexpec(void)
{
	ft_printf(2, GREEN "MiniShell: " \
		WHITE "syntax error unexpected token `&'\n");
	return (-1);
}

void	share_call_or(t_shell *shell, int i)
{
	char	*before;
	char	*after;

	before = ft_substr(shell->call->cmd, 0, i - 1);
	after = ft_substr(shell->call->cmd, i + 1, \
	ft_strlen(shell->call->cmd) - i);
	add_after_or(after, shell);
	add_after_or(before, shell);
	shell->call->next->status = 0;
	delete_this(shell);
}

int	or_case(t_shell *shell, int *i)
{
	int	j;

	(*i)++;
	j = (*i) + 1;
	while (shell->call->cmd[j] == ' ')
		j++;
	if (shell->call->cmd[j] == '\0')
		return (or_tmp());
	j = (*i) - 1;
	while (j >= 0)
	{
		if (shell->call->cmd[j] != ' ' && shell->call->cmd[j] != '|')
			break ;
		j--;
	}
	if (j == -1)
	{
		ft_printf(2, GREEN "MiniShell: " \
		WHITE "syntax error unexpected token `||'\n");
		ft_first_call(&shell->call);
		return (-1);
	}
	share_call_or(shell, *i);
	return (1);
}

int	some_case(t_shell *shell, int *i)
{
	if (shell->call->cmd[(*i)] == '|')
	{
		if (shell->call->cmd[(*i) + 1] == '|')
			return (or_case(shell, i));
		return (pipe_case(shell, i));
	}
	else if (shell->call->cmd[(*i)] == '&')
	{
		if (shell->call->cmd[(*i) + 1] == '&')
			return (and_case(shell, i));
		return (unexpec());
	}
	return (0);
}
