/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:39:50 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/06 19:47:09 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_tmp(int *pid, t_file **file)
{
	(*pid) = -1;
	ft_first_file(file);
}

void	find_tmp2(t_pipe **pipe_in)
{
	close((*pipe_in)->fd[1]);
	dup2((*pipe_in)->fd[0], 0);
}

int	find_tmp3(char *name)
{
	ft_printf(2, GREEN "MiniShell: " \
	WHITE "%s: No such file or directory\n", name);
	return (-1);
}

int	find_tmp4(t_file **file)
{
	int	out;

	out = 0;
	if ((*file)->status == 1)
		out = open((*file)->name, O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if ((*file)->status == 2)
		out = open((*file)->name, O_RDWR | O_APPEND | O_CREAT, 0644);
	return (out);
}

int	find_tmp5(t_pipe **pipe_out)
{
	close((*pipe_out)->fd[0]);
	dup2((*pipe_out)->fd[1], 1);
	return (1);
}
