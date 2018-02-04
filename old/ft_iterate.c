/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 20:12:01 by adaly             #+#    #+#             */
/*   Updated: 2017/06/14 05:00:44 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

uintmax_t	ft_iterate(t_pscell ***ablist, uintmax_t size, \
char **moveset, char **solution)
{
	t_pscell	**results[2];
	char		*best_moves;
	uintmax_t	scores[2];

	scores[0] = 0;
	if (ablist && depth && moveset)
	{
		while (*moveset)
		{
			results[1] = ft_apply_moves(*ablist, *moveset, size);
			if ((scores[1] = ft_score(temp, size)) > scores[0])
			{
				if (results[0])
					free(results[0]);
				scores[0] = scores[1];
				best_moves = *moveset;
				results[0] = results[1];
			}
			else
				free(results[1]);
			++moveset;
		}
		ft_restrcat(solution, best_moves);
		ft_free_pslist(*ablist);
		*ablist = results[0];
	}
	return (scores[0]);
}
