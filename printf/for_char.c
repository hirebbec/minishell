/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:58:08 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:09 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_struct	without_flag(t_struct ptf, char c)
{
	while (ptf.width > 1)
	{
		ptf = ft_putchar(ptf, ' ');
		ptf.width--;
	}
	ptf = ft_putchar(ptf, c);
	return (ptf);
}

static	t_struct	flag_zero(t_struct ptf, char c)
{
	while (ptf.width > 1)
	{
		ptf = ft_putchar(ptf, '0');
		ptf.width--;
	}
	ptf = ft_putchar(ptf, c);
	return (ptf);
}

static	t_struct	flag_minus(t_struct ptf, char c)
{
	ptf = ft_putchar(ptf, c);
	while (ptf.width > 1)
	{
		ptf = ft_putchar(ptf, ' ');
		ptf.width--;
	}
	return (ptf);
}

t_struct	for_char(t_struct ptf, char c)
{
	if (c != '%')
		c = va_arg(ptf.ap, int);
	if (ptf.flag == '-')
		ptf = flag_minus(ptf, c);
	else if (ptf.flag == 0)
		ptf = flag_zero(ptf, c);
	else
		ptf = without_flag(ptf, c);
	return (ptf);
}
