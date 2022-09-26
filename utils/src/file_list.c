/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:20:21 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/18 20:39:17 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file	*new_file(char *name, int status, int type)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (new == NULL)
		exit(1);
	new->name = name;
	new->status = status;
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_first_file(t_file **file)
{
	while ((*file)->prev)
		*file = (*file)->prev;
}

void	ft_last_file(t_file **file)
{
	while ((*file)->next)
		*file = (*file)->next;
}

void	add_back_file(t_file **file, char *name, int status, int type)
{
	t_file	*new;

	new = new_file(name, status, type);
	ft_last_file(file);
	new->prev = (*file);
	(*file)->next = new;
}

void	return_fd(t_shell *shell);
void	ft_execve(char	**cmds, t_shell *shell);

void	ft_tmp9(t_shell *shell, char **cmds)
{
	if (shell->paths)
		ft_execve(cmds, shell);
	else
	{
		ft_printf(2, GREEN "MiniShell: " WHITE "%s: command not found\n", \
		cmds[0]);
		g_status = 127;
	}
	free_mat(cmds);
	return_fd(shell);
	shell->call = shell->call->next;
}
