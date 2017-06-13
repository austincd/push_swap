/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:34:24 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 04:20:09 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

uintmax_t	ft_pslsize(t_pscell *list)
{
	uintmax_t	size;

	size = 0;
	if (list)
	{
		while (list[size].next != list)
			++size;
	}
	return (size + 1);
}
