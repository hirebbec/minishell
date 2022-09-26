/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:58:33 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:34 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_struct	ft_for_else(t_struct ptf, char *str)
{
	int	len;

	len = ft_strlen_p(str);
	while (ptf.width > len && ptf.temp_w > 0)
	{
		ptf = ft_putchar(ptf, ' ');
		ptf.width--;
	}
	while (*str && ptf.accuracy)
	{
		ptf = ft_putchar(ptf, *str);
		str++;
		ptf.accuracy--;
	}
	while (ptf.width > len && ptf.temp_w < 0)
	{
		ptf = ft_putchar(ptf, ' ');
		ptf.width--;
	}
	return (ptf);
}

static	t_struct	without_flag(t_struct ptf, char *str)
{
	if (ptf.accuracy == -2)
		ptf.accuracy = ft_strlen_p(str);
	if (ptf.width >= ptf.accuracy)
	{
		while (ptf.width > ptf.accuracy && ptf.width)
		{
			ptf = ft_putchar(ptf, ' ');
			ptf.width--;
		}
		while (ptf.accuracy > ft_strlen_p(str))
		{
			ptf = ft_putchar(ptf, ' ');
			ptf.accuracy--;
		}
		while (*str && ptf.accuracy)
		{
			ptf = ft_putchar(ptf, *str);
			str++;
			ptf.accuracy--;
		}
	}
	else
		ptf = ft_for_else(ptf, str);
	return (ptf);
}

static	t_struct	flag_zero(t_struct ptf, char *str)
{
	int	i;

	i = 0;
	if (ptf.accuracy == -2)
		ptf.accuracy = ft_strlen_p(str);
	if (ptf.width >= ptf.accuracy)
	{
		while (ptf.width != ptf.accuracy)
		{
			ptf = ft_putchar(ptf, '0');
			ptf.width--;
		}
		while (ptf.width >= 1 && str[i] && ptf.accuracy)
		{
			ptf = ft_putchar(ptf, str[i]);
			i++;
			ptf.accuracy--;
		}
	}
	else
		ptf = ft_for_else(ptf, str);
	return (ptf);
}

static	t_struct	flag_minus(t_struct ptf, char *str)
{
	int	i;

	i = 0;
	if (ptf.accuracy == -2)
		ptf.accuracy = ft_strlen_p(str);
	if (ptf.width >= ptf.accuracy)
	{
		while (str[i] && ptf.accuracy)
		{
			ptf = ft_putchar(ptf, str[i]);
			i++;
			ptf.width--;
			ptf.accuracy--;
		}
		while (ptf.width > 0)
		{
			ptf = ft_putchar(ptf, ' ');
			ptf.width--;
		}
	}
	else
		ptf = ft_for_else_sminus(ptf, str);
	return (ptf);
}

t_struct	for_string(t_struct ptf)
{
	char	*str;

	str = va_arg(ptf.ap, char *);
	if (str == NULL)
		str = "(null)";
	if (ptf.temp < 0)
	{
		ptf.accuracy = ft_strlen_p(str);
	}
	if (ptf.flag == '-')
		ptf = flag_minus(ptf, str);
	else if (ptf.flag == 0)
		ptf = flag_zero(ptf, str);
	else
		ptf = without_flag(ptf, str);
	return (ptf);
}
