/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_osift_beta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 21:32:03 by adaly             #+#    #+#             */
/*   Updated: 2017/10/05 07:26:24 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

char	*ft_iteration_osiftb(t_pscell **ablist, uintmax_t size, int which_list, char *to_remove, char *selstr)
{
	char		*best;
	intmax_t	best_topush;
	intmax_t	pushto;
	intmax_t	radius;
	intmax_t	limit;

//	limit = (intmax_t)((size / 2) + 2);
	limit = 260;
//	if ((ft_psllength(ablist[which_list ? 0 : 1]) * 2) > size)
//		 limit = 4;
	pushto = -1;
	best_topush = -1;
	radius = -1;
	best = NULL;
	if (ft_charcount(to_remove, '1') == 1)
		return (ft_find_final_spot(ablist, (ft_strchr(to_remove, '1') - to_remove) + 1, selstr));
	while ((pushto == -1 || best_topush == -1) && radius < limit)
	{
		++radius;
		if (ft_charcount(selstr, '1') >= 2)
		{
			best_topush = ft_orderedpushselstr(ablist, size, radius, which_list, to_remove, selstr);
			pushto = ft_find_right_spot_selstr(ablist, size, (best_topush + 1) * (which_list ? -1 : 1), selstr);
		}
		else
		{
			best_topush = (ft_strchr(to_remove, '1') - to_remove);
			if (!ft_charcount(selstr, '1'))
				pushto = 0;
			else
			{
				pushto = 0;
				if (ablist[which_list][best_topush].correct < ablist[(which_list ? 0 : 1)][0].correct)
					pushto = 1;
			}
		}
	}
	if (pushto >= 0 && best_topush >= 0)
	{
		best = ft_speed_surfacing(ablist, best_topush, pushto);
		if (best)
			best[ft_strlen(best)] = which_list ? '1' : '2';
	}
	return (best);
}

static void	ft_update_selstr(char *selstr, char *to_remove, char *moves)
{
	int	counter;

	counter = -1;
	if (selstr && moves)
	{
		while (moves[++counter])
		{
			if (moves[counter] == 'A')
			{
				ft_selstr_rot(selstr);
				ft_selstr_rot(to_remove);
			}
			if (moves[counter] == 'B')
			{
				ft_selstr_revrot(selstr);
				ft_selstr_revrot(to_remove);
			}
			if (moves[counter] == '2')
				ft_selstr_push(to_remove, selstr);
			(moves[counter] == '6') ? ft_selstr_rot(to_remove) : 1;
			(moves[counter] == '8') ? ft_selstr_revrot(to_remove) : 1;
			(moves[counter] == '7') ? ft_selstr_rot(selstr) : 1;
			(moves[counter] == '9') ? ft_selstr_revrot(selstr) : 1;
		}
	}
}

char	*ft_osift_beta(t_pscell **ablist, uintmax_t size, int which_list, char *to_remove)
{
	char		*solution;
	char		*moves;
	t_pscell	**duplicate;
	char		*selstr;

	solution = ft_strnew(5000);
	duplicate = ablist ? ft_psldup(ablist, size) : NULL;
	moves = NULL;
	selstr = ft_strnew(1000);//ft_strnew(ft_psllength(duplicate[1]));
//	printf("selstr is %s\n", selstr);
//	solution[0] = '2';
//	solution[1] = '2';
//	ft_apply_moves(duplicate, solution, size, 0);
//	ft_selstr_push(to_remove, selstr);
//	ft_selstr_push(to_remove, selstr);
	selstr ? ft_memset(selstr, '0', ft_psllength(duplicate[1])) : NULL;
//	selstr ? ft_memset(selstr, '1', 2) : NULL;
//	printf("selstr is %s\n", selstr);
//	printf("to_remove is %s\n", to_remove);
	if (duplicate && size && ft_psllength(duplicate[which_list]) && to_remove)
	{
		while (ft_charcount(to_remove, '1') && (moves = ft_iteration_osiftb(duplicate, size, which_list, to_remove, selstr)))
		{
			if (moves)
			{
//				printf("selstr is %s\n", selstr);
//				printf("to_remove is %s\n", to_remove);
//				printf("moves are %s\n", moves);
				ft_apply_moves(duplicate, moves);
				ft_update_selstr(selstr, to_remove, moves);
				ft_strcat(solution, moves);
//				printf("ordered sift is now %s\n", solution);
//				getchar();
//				ft_strdel_plus(&moves);
			}
		}
	}
	return (solution);
}

char	*ft_rotto_highest(t_pscell **ablist, uintmax_t size, char which_list)
{
	int		edge;
	char	*opts;

	opts = NULL;
	if (ablist && size)
	{
		edge = ft_sifting_edge(ablist, which_list);
		if (edge >= 0)
		{
			opts = ft_speed_surfacing(ablist, 0, edge);
			if (opts)
				ft_apply_moves(ablist, opts);
		}
	}
	return (opts);
}

char	*ft_osift_multi(t_pscell **ablist, uintmax_t size, int which_list, char *to_remove, int factor)
{
	char		*solution;
	char		*moves;
	t_pscell	**duplicate;
	char		*selstr;
	int			counter;

	counter = 0;
	solution = ft_strnew(5000);
	duplicate = ablist ? ft_psldup(ablist, size) : NULL;
	moves = NULL;
	selstr = ft_strnew(1000);
	selstr ? ft_memset(selstr, '0', ft_psllength(duplicate[1])) : NULL;
	if (duplicate && size && ft_psllength(duplicate[which_list]) && to_remove)
	{
		factor = ft_charcount(to_remove, '1') / factor;
//		printf("factor is %i\n", factor);
//		getchar();
		while (ft_charcount(to_remove, '1') && (moves = ft_iteration_osiftb(duplicate, size, which_list, to_remove, selstr)))
		{
//			printf("to_remove is %s\n", to_remove);
//			printf("counter is %i\n", counter);
//			getchar();
			if (moves)
			{
//				printf("moves are %s\n", moves);
				ft_apply_moves(duplicate, moves);
				ft_update_selstr(selstr, to_remove, moves);
				ft_strcat(solution, moves);
//				printf("ordered sift is now %s\n", solution);
//				getchar();
//				ft_strdel_plus(&moves);
				++counter;
				if (!(counter % factor))
				{
					if (counter == factor)
					{
						moves = ft_rotto_highest(duplicate, size, 1);
						if (moves)
						{
							ft_strcat(solution, moves);
							ft_update_selstr(selstr, to_remove, moves);
						}
//						ft_update_selstr(selstr, to_remove, moves, which_list);
	//					ft_strdel_plus(&moves);
					}
					ft_memset(selstr, '0', ft_strlen(selstr));
				}
			}
		}
	}
//	printf("charcount: %ju\n", ft_charcount(to_remove, '1'));
//	getchar();
	return (solution);
}
