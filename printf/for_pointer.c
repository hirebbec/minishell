/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:58:24 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:25 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_struct	ft_for_else(t_struct ptf, unsigned long nb)
{
	if (nb > 0)
	{
		while (ptf.accuracy > ft_diglenlong(nb) && ptf.accuracy-- > 0)
			ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, 'x');
		ptf = ft_putnbrlong(ptf, nb);
	}
	else if (nb == 0)
	{
		ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, 'x');
		while (ptf.accuracy-- > 1)
			ptf = ft_putchar(ptf, '0');
	}
	else
	{
		while (ptf.accuracy - ptf.width > 0 && ptf.accuracy-- > 0)
			ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, 'x');
		ptf = ft_putnbrlong(ptf, nb);
	}
	return (ptf);
}

static	t_struct	flag_minus(t_struct ptf, unsigned long nb)
{
	int	count;

	count = 0;
	if (ptf.width >= ptf.accuracy)
	{
		while (ptf.accuracy > ft_diglenlong(nb))
		{
			ptf = ft_putchar(ptf, '0');
			ptf.accuracy--;
			count++;
		}
		ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, 'x');
		ptf = ft_putnbrlong(ptf, nb);
		while ((ptf.width - ft_diglenlong(nb) - count - 2) > 0)
		{
			ptf = ft_putchar(ptf, ' ');
			ptf.width--;
		}
	}
	else
		ptf = ft_for_else(ptf, nb);
	return (ptf);
}

static	t_struct	flag_zero(t_struct ptf, unsigned long nb)
{
	if (ptf.width >= ptf.accuracy)
	{
		if (ptf.accuracy == -2)
		{
			ptf = ft_putchar(ptf, '0');
			ptf = ft_putchar(ptf, 'x');
			while ((ptf.width-- > ft_diglenlong(nb) + 2) && ptf.width)
				ptf = ft_putchar(ptf, '0');
			ptf = ft_putnbrlong(ptf, nb);
		}
		else if (ptf.accuracy == 0 && nb != 0)
		{
			while (ptf.width - ft_diglenlong(nb) > 0 && ptf.width-- > 0)
				ptf = ft_putchar(ptf, ' ');
			ptf = ft_putchar(ptf, '0');
			ptf = ft_putchar(ptf, 'x');
			ptf = ft_putnbrlong(ptf, nb);
		}
		else
			ptf = about_p(ptf, nb);
	}
	else
		ptf = ft_for_else(ptf, nb);
	return (ptf);
}

static	t_struct	without_flag(t_struct ptf, unsigned long nb)
{
	if (ptf.accuracy == 0)
	{
		while (ptf.width - ft_diglenlong(nb) - 2 > 0 && ptf.width-- > 0)
			ptf = ft_putchar(ptf, ' ');
		ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, 'x');
		if (nb != 0)
			ptf = ft_putnbrlong(ptf, nb);
	}
	else if (nb == 0 && ptf.width == 0)
	{
		ptf = ft_putchar(ptf, '0');
		ptf = ft_putchar(ptf, 'x');
		ptf = ft_putnbrlong(ptf, nb);
	}
	else if (ptf.width >= ptf.accuracy)
		ptf = about_p(ptf, nb);
	else
		ptf = ft_for_else(ptf, nb);
	return (ptf);
}

t_struct	for_pointer(t_struct ptf)
{
	unsigned long	nb;

	nb = va_arg(ptf.ap, unsigned long);
	ptf = ft_point_2(ptf, nb);
	if (ptf.flag == '-')
		ptf = flag_minus(ptf, nb);
	else if (ptf.flag == 0)
	{
		if (ptf.accuracy < ft_diglenlong(nb) && ptf.accuracy != -2)
			ptf.accuracy = ft_diglenlong(nb);
		else if (ptf.accuracy < ft_diglenlong(nb) && ptf.accuracy != -2)
			ptf.accuracy = ft_strlen_inint(nb);
		ptf = flag_zero(ptf, nb);
	}
	else
		ptf = without_flag(ptf, nb);
	return (ptf);
}
