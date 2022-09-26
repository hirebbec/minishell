/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:12:43 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 20:02:18 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_call	*new_call(char *cmd)
{
	t_call	*new;

	new = malloc(sizeof(t_call));
	if (new == NULL)
		exit(1);
	new->cmd = cmd;
	new->file = NULL;
	new->pipe_in = NULL;
	new->pipe_out = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->status = 0;
	return (new);
}

void	add_back_call(t_call **call, char *cmd)
{
	t_call	*new;

	new = new_call(cmd);
	ft_last_call(call);
	new->prev = (*call);
	(*call)->next = new;
}

void	ft_first_call(t_call **call)
{
	while ((*call)->prev)
		*call = (*call)->prev;
}

void	ft_last_call(t_call **call)
{
	while ((*call)->next)
		*call = (*call)->next;
}

void	delete_call(t_call **call)
{
	ft_last_call(call);
	if (ft_strlen((*call)->cmd) == 0)
	{
		(*call) = (*call)->prev;
		(*call)->next = NULL;
	}
}
