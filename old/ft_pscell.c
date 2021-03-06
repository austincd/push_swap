/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pscell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:42:51 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 18:48:39 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		ft_psczero(t_pscell *target)
{
	if (target)
	{
		(*target).value = 0;
		(*target).correct = 0;
		(*target).current = 0;
		(*target).next = 0;
	}
}
