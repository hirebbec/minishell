/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:59:43 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 19:03:59 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tmp3(char *str);
void	ft_tmp4(char *str);

void	ft_execve(char	**cmds, t_shell *shell)
{
	if (shell->call->pipe_out)
	{
		if (!shell_cmd_try(cmds, shell))
			ft_tmp4(cmds[0]);
	}
	else if (!ft_strncmp("pwd", cmds[0], 3) && ft_strlen(cmds[0]) == 3)
		ft_pwd();
	else if (!ft_strncmp("echo", cmds[0], 4) && ft_strlen(cmds[0]) == 4)
		ft_echo(cmds, 1);
	else if (!ft_strncmp("env", cmds[0], 3) && ft_strlen(cmds[0]) == 3)
		ft_env(shell, cmds);
	else if (!ft_strncmp("unset", cmds[0], 5) && ft_strlen(cmds[0]) == 5)
		ft_unset(shell, cmds);
	else if (!ft_strncmp("export", cmds[0], 6) && ft_strlen(cmds[0]) == 6)
		ft_export(shell, cmds, 1, "");
	else if (!ft_strncmp("cd", cmds[0], 2) && ft_strlen(cmds[0]) == 2)
	{
		ft_cd(cmds, shell->env);
		shell->cd_flag = 1;
	}
	else if (!ft_strncmp("exit", cmds[0], 4) && ft_strlen(cmds[0]) == 4)
		ft_exit(cmds);
	else
		if (!shell_cmd_try(cmds, shell))
			ft_tmp3(cmds[0]);
}

void	ft_tmp5(t_file *file);
void	ft_tmp6(t_file *file, char *text);

void	here_doc(t_file *file)
{
	char	*input;
	char	*text;
	int		pid;

	input = "start";
	text = "";
	pipe(file->fd);
	pid = fork();
	if (pid == 0)
	{
		here_doc_signal();
		while (ft_strncmp(input, file->name, ft_strlen(input)) || \
			ft_len_dif(input, file->name) != 0)
		{
			input = readline(">");
			if (ft_strncmp(input, file->name, ft_strlen(input)) || \
			ft_len_dif(input, file->name) != 0)
			{
				text = ft_strjoin(text, input);
				text = ft_strjoin(text, "\n");
			}
		}
		ft_tmp6(file, text);
	}
	ft_tmp5(file);
}

void	find_tmp(int *pid, t_file **file);
void	find_tmp2(t_pipe **pipe_in);
int		find_tmp3(char *name);
int		find_tmp4(t_file **file);
int		find_tmp5(t_pipe **pipe);
int		find_tmp6(void);
void	find_tmp7(t_pipe **pipe_out);
void	find_tmp8(int *pid, t_file **file, t_pipe **pipe);
int		find_tmp9(int *pid, t_pipe **pipe_out);
int		find_tmp10(t_file **file);
int		find_tmp11(t_file **file);

int	ft_redirect(t_file *file, t_pipe *pipe_in, t_pipe *pipe_out, int pid)
{
	find_tmp8(&pid, &file, &pipe_in);
	while (file->next)
	{
		if (file->type == 0)
		{
			if (file->status == 2)
				here_doc(file);
			else if (file->status == 1)
				if (!find_tmp10(&file))
					return (-1);
		}
		else
			if (!find_tmp11(&file))
				return (-1);
		file = file->next;
	}
	if (pipe_out)
	{
		if (pid == 0)
			find_tmp7(&pipe_out);
		else if (pid < 0)
			return (find_tmp9(&pid, &pipe_out));
	}
	return (1);
}

void	return_fd(t_shell *shell)
{
	dup2(shell->std_in, STDIN_FILENO);
	dup2(shell->std_out, STDOUT_FILENO);
}

void	ft_tmp7(t_shell *shell);
void	ft_tmp8(t_shell *shell, char **cmds);
void	ft_tmp9(t_shell *shell, char **cmds);
int		ft_genyi(t_shell *shell);

int	ft_find(t_shell *shell)
{
	int		flag;
	char	**cmds;

	ft_first_call(&shell->call);
	while (shell->call->next)
	{
		if (ft_genyi(shell))
			continue ;
		shell->call->cmd = ft_strtrim_free(shell->call->cmd, " ");
		cmds = ft_convert(true_cmds(shell->call->cmd), shell);
		flag = ft_redirect(shell->call->file, shell->call->pipe_in, \
		shell->call->pipe_out, 1);
		if (flag != 1)
		{
			ft_tmp8(shell, cmds);
			continue ;
		}
		ft_tmp9(shell, cmds);
	}
	return (0);
}
