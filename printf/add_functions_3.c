/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:57:59 by hirebbec          #+#    #+#             */
/*   Updated: 2022/04/08 20:58:00 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	ft_point_2(t_struct ptf, unsigned long nb)
{
	if (ptf.temp < 0)
	{
		ptf.width = ft_diglenlong(nb) + 2;
		ptf.accuracy = 1;
	}
	if (ptf.flag != 0)
	{
		if (ptf.accuracy < ft_diglenlong(nb) && ptf.accuracy != 0)
			ptf.accuracy = ft_diglenlong(nb);
	}
	return (ptf);
}
