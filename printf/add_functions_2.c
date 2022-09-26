/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:57:54 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:57:55 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	ft_for_else_sminus(t_struct ptf, char *str)
{
	int	len;

	len = ft_strlen_p(str);
	while (*str && ptf.accuracy)
	{
		ptf = ft_putchar(ptf, *str);
		str++;
		ptf.accuracy--;
	}
	while (ptf.width > len)
	{
		ptf = ft_putchar(ptf, ' ');
		ptf.width--;
	}
	return (ptf);
}

t_struct	ft_space_1(t_struct ptf, char *str)
{
	int	k;

	k = 0;
	while (str[ptf.i] == ' ')
	{
		ptf.i++;
		ptf.space++;
		k++;
	}
	if (k > 0)
		ptf = ft_putchar(ptf, ' ');
	return (ptf);
}

t_struct	ft_endof_accaracy(t_struct ptf, char *str)
{
	ptf.accuracy = va_arg(ptf.ap, int);
	ptf.temp = ptf.accuracy;
	if (ptf.accuracy < 0 && if_s(ptf, str) == 0)
	{
		if (ptf.width == 0)
		{
			ptf.flag = '-';
			ptf.accuracy = 1;
		}
		else if (ptf.flag == 0)
		{
			ptf.accuracy = ptf.width;
		}
	}
	ptf.i++;
	return (ptf);
}

t_struct	ft_dig_min(t_struct ptf, int nb)
{
	if (ptf.temp < 0)
		ptf.accuracy = 1;
	if ((ptf.accuracy < ft_strlen_nb(nb)) && (ptf.accuracy || nb))
		ptf.accuracy = ft_strlen_nb(nb);
	return (ptf);
}

t_struct	ft_dig_zero(t_struct ptf, int nb)
{
	if (ptf.accuracy == -2)
	{
		if (ptf.minus == 1)
			ptf = ft_putchar(ptf, '-');
		while ((ptf.width > ft_strlen_nb(nb)) && ptf.width-- > 0)
			ptf = ft_putchar(ptf, '0');
	}
	else
	{
		while ((ptf.width > ptf.accuracy) && ptf.width-- > 0)
			ptf = ft_putchar(ptf, ' ');
		if (ptf.minus == 1)
			ptf = ft_putchar(ptf, '-');
		while (ptf.accuracy > ft_strlen_nb(nb) && ptf.accuracy-- > 0)
			ptf = ft_putchar(ptf, '0');
	}
	ptf = ft_putnbr(ptf, nb);
	return (ptf);
}
