/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:03:11 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 14:50:30 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	list_len(t_env *env)
{
	int	i;

	i = 1;
	ft_first_element(&env);
	while (env->next)
	{
		i++;
		env = env->next;
	}
	return (i);
}

void	ft_tmp5(t_file *file)
{
	signal(SIGINT, SIG_IGN);
	wait(NULL);
	signal_main();
	close(file->fd[1]);
	dup2(file->fd[0], 0);
}

void	ft_tmp6(t_file *file, char *text)
{
	close(file->fd[0]);
	ft_printf(file->fd[1], "%s", text);
	exit(0);
}

void	ft_tmp7(t_shell *shell)
{
	ft_printf(2, GREEN "MiniShell: " WHITE);
	ft_printf(2, ": command not found\n");
	shell->call = shell->call->next;
}

void	return_fd(t_shell *shell);

void	ft_tmp8(t_shell *shell, char **cmds)
{
	return_fd(shell);
	shell->call = shell->call->next;
	free_mat(cmds);
}
