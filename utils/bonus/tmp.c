/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:47:15 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/15 21:14:17 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	and_tmp(void)
{
	ft_printf(2, GREEN "MiniShell: " \
	WHITE "syntax error unexpected token `&&'\n");
	return (-1);
}

void	add_after_and(char *cmd, t_shell *shell)
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
	shell->call->next->status = 2;
}

void	ft_tmp7(t_shell *shell);

int	ft_genyi(t_shell *shell)
{
	if (shell->call->status == 1 && g_status == 0)
	{
		shell->call = shell->call->next;
		return (1);
	}
	else if (shell->call->status == 2 && g_status != 0)
	{
		shell->call = shell->call->next;
		return (1);
	}
	if (ft_strlen(shell->call->cmd) == 0)
	{
		ft_tmp7(shell);
		return (1);
	}
	return (0);
}

int		star_check(char *input, t_star *star);

char	*get_dir(char *before, int i)
{
	char	*path;

	path = malloc(1);
	path[0] = 0;
	while (before[i] != ' ' && i > -1)
	{
		path = ft_joinchar_free(path, before[i]);
		i--;
	}
	return (path);
}

char	*get_new_input(char *input, int i);

void	go_pwd(char **input, t_shell *shell, int i, char **cmds)
{
	t_star	star;

	cmds = malloc(sizeof(char *) * 3);
	cmds[0] = "cd";
	if (star_check((*input), &star))
	{
		while (star.before[i])
		{
			if (star.before[i] == '/')
			{	
				cmds[1] = get_dir(star.before, i);
				ft_cd(cmds, shell->env);
				cmds[2] = NULL;
				star.before = ft_substr_free(star.before, i + 1, \
				ft_strlen(star.before) - i);
				(*input) = get_new_input((*input), i);
				free(cmds[1]);
				i = 0;
			}
			i++;
		}
		free(star.before);
		free(star.after);
	}
	free(cmds);
}
