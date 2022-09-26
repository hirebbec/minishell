/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:27:26 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/06 20:39:13 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	find_tmp11(t_file **file)
{
	int	out;

	out = find_tmp4(file);
	if (out < 0)
		return (find_tmp3((*file)->name));
	dup2(out, 1);
	return (1);
}
