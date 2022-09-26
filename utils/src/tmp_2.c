/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:49:12 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 20:37:12 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_tmp(int *pid, t_file **file);
void	find_tmp2(t_pipe **pipe_in);
int		find_tmp3(char *name);
int		find_tmp4(t_file **file);
int		find_tmp5(t_pipe **pipe);

int	find_tmp6(void)
{
	wait(NULL);
	return (2);
}

void	find_tmp7(t_pipe **pipe_out)
{
	close((*pipe_out)->fd[0]);
	dup2((*pipe_out)->fd[1], 1);
}

void	find_tmp8(int *pid, t_file **file, t_pipe **pipe)
{
	find_tmp(pid, file);
	if (*pipe)
		find_tmp2(pipe);
}

int	find_tmp9(int *pid, t_pipe **pipe_out)
{
	(*pid) = fork();
	if ((*pid) == 0)
		return (find_tmp5(pipe_out));
	else
		return (find_tmp6());
}

int	find_tmp10(t_file **file)
{
	int	in;

	in = open((*file)->name, O_RDONLY);
	if (in < 0)
		return (find_tmp3((*file)->name));
	dup2(in, 0);
	return (1);
}
