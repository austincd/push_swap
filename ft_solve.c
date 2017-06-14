/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 04:32:59 by adaly             #+#    #+#             */
/*   Updated: 2017/06/14 04:40:13 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_solve(t_pscell **ablist)
{
	char		**moveset;
	uintmax_t	depth;
	uintmax_t	size;
	int			status;
	char		*solution;

	status = 0;
	solution = NULL;
	size = ft_pslsize(ablist[0]);
	depth = 5;
//	depth = ft_calculate_depth(ablist, size);
	moveset = NULL;
	moveset = ft_generate_moves(depth);
	while (!status)
		status = ft_iterate(ablist, size, moveset, &solution);
	return (solution);
}
