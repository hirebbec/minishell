/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:32:10 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 21:50:54 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_after(char *cmd, int fd[2], t_shell *shell, int s)

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
	if (s == 0)
		shell->call->next->pipe_in = new_pipe(fd);
	else
	{
		shell->call->next->pipe_out = new_pipe(fd);
		if (shell->call->pipe_in)
			shell->call->next->pipe_in = shell->call->pipe_in;
	}
}

void	delete_this(t_shell *shell)
{
	t_call	*tmp;

	if (shell->call->prev == NULL)
	{
		shell->call = shell->call->next;
		free(shell->call->prev->cmd);
		free(shell->call->prev);
		shell->call->prev = NULL;
	}
	else
	{
		tmp = shell->call->prev;
		shell->call = shell->call->next;
		free(shell->call->prev->cmd);
		free(shell->call->prev);
		tmp->next = shell->call;
		shell->call->prev = tmp;
	}
}

void	share_call(t_shell *shell, int i)
{
	char	*before;
	char	*after;
	int		fd[2];

	pipe(fd);
	before = ft_substr(shell->call->cmd, 0, i);
	after = ft_substr(shell->call->cmd, i + 1, \
	ft_strlen(shell->call->cmd) - i);
	add_after(after, fd, shell, 0);
	add_after(before, fd, shell, 1);
	delete_this(shell);
}

int	ft_tmp12(void);
int	some_case(t_shell *shell, int *i);

int	pipe_case(t_shell *shell, int *i)
{
	int	j;

	j = (*i) + 1;
	while (shell->call->cmd[j] == ' ')
		j++;
	if (shell->call->cmd[j] == '\0')
		return (ft_tmp12());
	j = (*i) - 1;
	while (j >= 0)
	{
		if (shell->call->cmd[j] != ' ')
			break ;
		j--;
	}
	if (j == -1)
	{
		ft_printf(2, GREEN "MiniShell: " \
		WHITE "syntax error unexpected token `|'\n");
		ft_first_call(&shell->call);
		return (-1);
	}
	share_call(shell, *i);
	return (1);
}

int	some_case(t_shell *shell, int *i);

int	ft_pipe(t_shell *shell)
{
	int	i;

	ft_first_call(&shell->call);
	while (shell->call->next)
	{
		i = 0;
		while (shell->call->cmd[i])
		{
			if (shell->call->cmd[i] == ONE)
				one_cs(shell->call->cmd, &i);
			else if (shell->call->cmd[i] == TWO)
				two_cs(shell->call->cmd, &i);
			else if ((shell->call->cmd[i] == '|' || shell->call->cmd[i] == '&')
				&& shell->call->cmd[i - 1] != '\\')
			{
				if (some_case(shell, &i) < 0)
					return (-1);
				break ;
			}
			else
				i++;
		}
		shell->call = shell->call->next;
	}
	return (1);
}
