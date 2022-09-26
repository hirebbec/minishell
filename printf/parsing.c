/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:59:18 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:59:19 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_struct	type(t_struct ptf, char *str)
{
	if (str[ptf.i] == 'c' || str[ptf.i] == '%')
		ptf = for_char(ptf, str[ptf.i]);
	else if (str[ptf.i] == 's')
		ptf = for_string(ptf);
	else if (str[ptf.i] == 'i' || str[ptf.i] == 'd')
		ptf = for_digit(ptf);
	else if (str[ptf.i] == 'u')
		ptf = for_unsigned(ptf);
	else if (str[ptf.i] == 'x' || str[ptf.i] == 'X')
		ptf = for_hexadecimal(ptf, str[ptf.i]);
	else if (str[ptf.i] == 'p')
		ptf = for_pointer(ptf);
	else
		ptf = ft_putchar(ptf, str[ptf.i]);
	return (ptf);
}

t_struct	accuracy(t_struct ptf, char *str)
{
	ptf.i++;
	if ((str[ptf.i] >= 48 && str[ptf.i] <= 57) || str[ptf.i] == '-')
	{
		ptf = ft_atoi_accuracy(ptf, str);
		if (ptf.accuracy < 0)
		{
			ptf.width = ptf.accuracy * (-1);
			ptf.flag = '-';
			ptf.accuracy = 0;
		}
	}
	else if (str[ptf.i] == '*')
		ptf = ft_endof_accaracy(ptf, str);
	else
		ptf.accuracy = 0;
	return (ptf);
}

t_struct	width(t_struct ptf, char *str)
{
	if ((str[ptf.i] >= 48 && str[ptf.i] <= 57) || str[ptf.i] == '-')
	{	
		ptf = ft_atoi_width(ptf, str);
		ptf.temp_w = ptf.width;
	}
	else if (str[ptf.i] == '*')
	{
		ptf.width = va_arg(ptf.ap, int);
		ptf.temp_w = ptf.width;
		if (ptf.width < 0)
		{
			ptf.width = ptf.width * (-1);
			ptf.flag = '-';
		}
		ptf.i++;
	}
	return (ptf);
}

t_struct	flags(t_struct ptf, char *str)
{
	if (str[ptf.i] == '0')
	{
		ptf.flag = 0;
		ptf.i++;
	}
	if (str[ptf.i] == '-')
	{
		ptf.flag = '-';
		ptf.i++;
	}
	return (ptf);
}

t_struct	parsing(t_struct ptf, char *str)
{
	while (str[ptf.i])
	{
		if (str[ptf.i] == '%')
		{
			ptf.i++;
			ptf = second_init_struct(ptf);
			ptf = ft_space_1(ptf, str);
			ptf = flags(ptf, str);
			ptf = ft_space(ptf, str);
			if ((ptf.flag == '-') && (str[ptf.i] == '0'))
				ptf.i++;
			ptf = width(ptf, str);
			ptf = ft_space(ptf, str);
			if (str[ptf.i] == '.')
				ptf = accuracy(ptf, str);
			ptf = ft_space(ptf, str);
			if (ptf.count == -1)
				return (ptf);
			ptf = type(ptf, str);
		}
		else
			ptf = ft_putchar(ptf, str[ptf.i]);
		ptf.i++;
	}
	return (ptf);
}
