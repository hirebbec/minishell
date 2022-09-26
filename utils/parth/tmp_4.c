/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:02:42 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/07 16:06:22 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		redirect_outfile(int *i, t_shell *shell, int status, int start);
int		redirect_infile(int *i, t_shell *shell, int status, int start);

int	redic_tmp(t_shell *shell, int *i)
{
	if ((*i) != 0)
	{
		if (shell->call->cmd[(*i) - 1] != '\\')
		{
			if (!redirect_infile(i, shell, 1, 0))
				return (-1);
			else
				(*i) = 0;
		}
		else
			(*i)++;
	}
	else
	{
		if (!redirect_infile(i, shell, 1, 0))
			return (-1);
		else
			(*i) = 0;
	}
	return (1);
}

int	redic_tmp2(t_shell *shell, int *i)
{
	if ((*i) != 0)
	{
		if (shell->call->cmd[(*i) - 1] != '\\')
		{
			if (!redirect_outfile(i, shell, 1, 0))
				return (-1);
			else
				(*i) = 0;
		}
		else
			(*i)++;
	}
	else
	{
		if (!redirect_outfile(i, shell, 1, 0))
			return (-1);
		else
			(*i) = 0;
	}
	return (1);
}

void	redic_tmp3(t_shell *shell, int *i)
{
	if (!shell->call->file)
		shell->call->file = new_file(ft_strdup("last"), -1, -1);
	else
		add_back_file(&shell->call->file, ft_strdup("last"), -1, -1);
	shell->call = shell->call->next;
	(*i) = 0;
}

void	one_case(int *i, char *cmd);
void	two_case(int *i, char *cmd);

void	redic_tmp4(t_shell *shell, int *i)
{
	if (shell->call->cmd[(*i)] == TWO)
		two_case(i, shell->call->cmd);
	else if (shell->call->cmd[(*i)] == ONE)
		one_case(i, shell->call->cmd);
	else
		(*i)++;
}
