/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:34:10 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/05 19:12:50 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_first_cmd(t_cmd **cmd)
{
	if (!(*cmd))
		return ;
	while ((*cmd)->prev)
		*cmd = (*cmd)->prev;
}

void	ft_last_cmd(t_cmd **cmd)
{
	if (!(*cmd))
		return ;
	while ((*cmd)->next)
		*cmd = (*cmd)->next;
}

void	add_back_cmd(t_cmd **cmd, char *comd)
{
	t_cmd	*new;

	new = new_cmd(comd);
	ft_last_cmd(cmd);
	new->prev = (*cmd);
	(*cmd)->next = new;
}

t_cmd	*new_cmd(char *cmd)
{
	t_cmd	*new;

	if (!cmd)
		return (NULL);
	new = malloc(sizeof(t_cmd));
	if (new == NULL)
		exit(1);
	new->tr_cmd = cmd;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_pipe	*new_pipe(int fd[2])
{
	t_pipe	*new;

	new = malloc(sizeof(t_pipe));
	if (new == NULL)
		exit(1);
	new->fd[0] = fd[0];
	new->fd[1] = fd[1];
	return (new);
}
