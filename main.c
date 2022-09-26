/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:59 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 15:00:51 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/minishell.h"

void	full_free(t_shell *shell)
{
	ft_first_call(&shell->call);
	while (shell->call->next)
	{
		free(shell->call->cmd);
		ft_first_file(&shell->call->file);
		while (shell->call->file->next)
		{
			free(shell->call->file->name);
			free(shell->call->file);
			shell->call->file = shell->call->file->next;
		}
		if (shell->call->pipe_in)
			free(shell->call->pipe_in);
		if (shell->call->pipe_out)
			free(shell->call->pipe_out);
		free(shell->call->file->name);
		free(shell->call->file);
		shell->call = shell->call->next;
		free(shell->call->prev);
	}
	free(shell->call);
}

t_env	*get_envp(char	**envp);
void	return_pwd(t_shell *shell);

void	usefull_func(int argc, char **argv, t_shell *shell, char **envp)
{
	(void)argc;
	(void)argv;
	full_free(shell);
	free(shell->oldpwd);
	if (!shell->export->next)
	{
		free_elem(shell->export);
		shell->export = get_envp(envp);
	}
}

int	main_tmp(char *tmp)
{
	(void)tmp;
	dprintf(2, GREEN "MiniShell: " WHITE ": command not found\n");
	free(tmp);
	return (0);
}

int	sk(char *input, char *tmp)
{
	tmp = ft_strtrim(input, " \t");
	if (tmp[0] == ONE)
	{
		tmp = ft_strtrim_free(tmp, "\'");
		tmp = ft_strtrim_free(tmp, " \t");
		if (!tmp)
			return (main_tmp(tmp));
	}
	else if (tmp[0] == TWO)
	{
		tmp = ft_strtrim_free(tmp, "\"");
		tmp = ft_strtrim_free(tmp, " \t");
		if (!tmp)
			return (main_tmp(tmp));
	}
	free(tmp);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_shell	shell;

	init(&shell, envp);
	while (1)
	{
		input = readline(GREEN "MiniShell: " WHITE);
		if (!input)
			exit(g_status);
		if (!ft_strlen(input) || !spaces(input) || !sk(input, "lol"))
		{
			free(input);
			continue ;
		}
		else
		{
			shell.call = ft_parth(input, &shell);
			if (ft_pipe(&shell) < 0)
				continue ;
			if (!redirect(&shell, 0))
				continue ;
			ft_find(&shell);
		}
		usefull_func(argc, argv, &shell, envp);
	}
}
