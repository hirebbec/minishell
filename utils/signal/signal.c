/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:16:31 by hirebbec          #+#    #+#             */
/*   Updated: 2022/05/13 21:51:44 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_ctrl_d_main(int sig)
{
	(void)sig;
	ft_putstr_fd("exit\n", 1);
	rl_replace_line("exit", 0);
	exit(g_status);
}

void	signal_main(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_ctrl_c_main);
}

void	sig_ctrl_c_hd(int sig)
{
	(void)sig;
	write(1, ">  \n", 4);
	exit(0);
}

void	here_doc_signal(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_ctrl_c_hd);
}
