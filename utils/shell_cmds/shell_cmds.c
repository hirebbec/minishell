/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:58:42 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/20 19:46:52 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_lol(int sig);

void	sig_kek(int sig)
{
	(void)sig;
	ft_printf(1, "Quit: 3\n");
	exit(131);
}

void	signal_child(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_lol);
}

char	**get_new_envp(t_env *env)
{
	char	**tmp;
	char	*lol;
	int		i;

	i = 0;
	ft_first_element(&env);
	tmp = malloc(sizeof(char *) * list_len(env) + 1);
	while (env->next)
	{
		lol = ft_strjoin(env->name, "=");
		tmp[i] = ft_strjoin_free(lol, env->value);
		i++;
		env = env->next;
	}
	lol = ft_strjoin(env->name, "=");
	tmp[i] = ft_strjoin_free(lol, env->value);
	tmp[i + 1] = NULL;
	return (tmp);
}

int	ft_exec(char *path, char **flags, t_shell *shell)
{
	pid_t	pid;
	char	**new_envp;

	new_envp = get_new_envp(shell->env);
	if (shell->call->pipe_out)
		execve(path, flags, new_envp);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			signal_child_cat();
			execve(path, flags, new_envp);
		}
		signal_child();
		wait(&g_status);
		g_status = g_status / 256;
		signal_main();
		free_mat(new_envp);
	}
	return (1);
}

int	shell_cmd_try(char **cmds, t_shell *shell)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	free_mat(shell->paths);
	get_paths(shell);
	if (!access(cmds[0], X_OK))
		return (ft_exec(cmds[0], cmds, shell));
	if (!shell->paths)
		return (0);
	while (shell->paths[i])
	{
		tmp = ft_strjoin(shell->paths[i], "/");
		path = ft_strjoin_free(tmp, cmds[0]);
		if (!access(path, X_OK))
		{
			ft_exec(path, cmds, shell);
			free(path);
			return (1);
		}
		free(path);
		i++;
	}
	return (0);
}
