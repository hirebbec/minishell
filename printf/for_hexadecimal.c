/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_hexadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:58:19 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:20 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_struct	ft_for_else(t_struct ptf, unsigned int nb, int type)
{
	if (nb > 0)
	{
		while (ptf.accuracy > ft_diglen16(nb))
		{
			ptf = ft_putchar(ptf, '0');
			ptf.accuracy--;
		}
		ptf = ft_putnbr16(ptf, nb, type);
	}
	else if ((unsigned int)nb == 0)
	{
		while (ptf.accuracy-- > 0)
			ptf = ft_putchar(ptf, '0');
	}
	else
	{
		while (ptf.accuracy - ptf.width > 0)
		{
			ptf = ft_putchar(ptf, '0');
			ptf.accuracy--;
		}
		ptf = ft_putnbr16(ptf, nb, type);
	}
	return (ptf);
}

static	t_struct	flag_minus(t_struct ptf, unsigned int nb, int type)
{
	int	count;

	count = 0;
	if (ptf.width >= ptf.accuracy)
	{
		while (ptf.accuracy > ft_diglen16(nb))
		{
			ptf = ft_putchar(ptf, '0');
			ptf.accuracy--;
			count++;
		}
		ptf = ft_putnbr16(ptf, nb, type);
		while ((ptf.width - ft_diglen16(nb) - count) > 0)
		{
			ptf = ft_putchar(ptf, ' ');
			ptf.width--;
		}
	}
	else
		ptf = ft_for_else(ptf, nb, type);
	return (ptf);
}

static	t_struct	flag_zero(t_struct ptf, unsigned int nb, int type)
{
	if (ptf.accuracy < ft_diglen16(nb) && ptf.accuracy != -2)
		ptf.accuracy = ft_diglen16(nb);
	else if (ptf.accuracy < ft_diglen16(nb) && ptf.accuracy != -2)
		ptf.accuracy = ft_strlen_inint(nb);
	if (ptf.width >= ptf.accuracy)
	{
		if (ptf.accuracy == -2)
		{
			while ((ptf.width-- > ft_diglen16(nb)) && ptf.width)
				ptf = ft_putchar(ptf, '0');
			ptf = ft_putnbr16(ptf, nb, type);
		}
		else if (ptf.accuracy == 0 && nb != 0)
		{
			while (ptf.width - ft_diglen16(nb) > 0 && ptf.width-- > 0)
				ptf = ft_putchar(ptf, ' ');
			ptf = ft_putnbr16(ptf, nb, type);
		}
		else
			ptf = about_x(ptf, nb, type);
	}
	else
		ptf = ft_for_else(ptf, nb, type);
	return (ptf);
}

static	t_struct	without_flag(t_struct ptf, unsigned int nb, int type)
{
	if (ptf.accuracy == 0)
	{
		if (nb == 0)
		{
			while (ptf.width > 0)
			{
				ptf = ft_putchar(ptf, ' ');
				ptf.width--;
			}
		}
		else
		{
			while (ptf.width - ft_diglen16(nb) > 0)
			{
				ptf = ft_putchar(ptf, ' ');
				ptf.width--;
			}
			ptf = ft_putnbr16(ptf, nb, type);
		}
	}
	else if (ptf.width >= ptf.accuracy)
		ptf = about_x(ptf, nb, type);
	else
		ptf = ft_for_else(ptf, nb, type);
	return (ptf);
}

t_struct	for_hexadecimal(t_struct ptf, int type)
{
	unsigned int	nb;

	nb = va_arg(ptf.ap, unsigned int);
	if (ptf.flag != 0)
	{
		if (ptf.accuracy < ft_diglen16(nb) && ptf.accuracy != 0)
			ptf.accuracy = ft_diglen16(nb);
	}
	if (ptf.accuracy == 0 && nb == 0)
	{
		while (ptf.width-- > 0)
			ptf = ft_putchar(ptf, ' ');
	}
	else if (ptf.flag == '-')
		ptf = flag_minus(ptf, nb, type);
	else if (ptf.flag == 0)
		ptf = flag_zero(ptf, nb, type);
	else
		ptf = without_flag(ptf, nb, type);
	return (ptf);
}
