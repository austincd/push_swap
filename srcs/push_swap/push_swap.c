/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:38:58 by adaly             #+#    #+#             */
/*   Updated: 2017/10/05 07:27:04 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_pushswap_for_basics(t_pscell **ablist, uintmax_t size, char *solution)
{
	char	*ascent;
	char	*str;
	int		counter;

	counter = 0;
	ascent = ft_find_best_ascent(ablist);
	ft_selstr_invert(ascent);
//	printf("to_remove is %s\n", ascent);
	str = ft_osift_multi(ablist, size, 0, ascent, 1);
//	printf("osift str is %s\n", str);
	ft_apply_moves(ablist, str);
//	ft_pslprint(ablist);
//	getchar();
	if (str)
		ft_strcat(solution, str);
	ft_strdel_plus(&str);
	while (ft_psllength(ablist[1]))
	{
		str = ft_merge_descent(ablist, size);
//	printf("merge str is %s\n", str);
//	ft_pslprint(ablist);
//	getchar();
		if (str)
			ft_strcat(solution, str);
		ft_strdel_plus(&str);
	}
	str = ft_final_round(ablist, size);
	if (str)
		ft_strcat(solution, str);
	ft_apply_moves(ablist, str);
//	printf("last str is %s\n", str);
//	ft_pslprint(ablist);
//	getchar();
	ft_strdel_plus(&str);
}

char	*ft_smallsolve(t_pscell **ablist)
{
	uintmax_t		size;
	char			*solution;

	size = ft_psllength(ablist[0]);
	solution = ft_strnew(1000);
	if (size && solution)
		ft_pushswap_for_basics(ablist, size, solution);
	return (solution);
}

//char	ft_select_smallest_bigsolve(t_pscell **ablist

char	*ft_bigsolve(t_pscell **ablist)
{
	uintmax_t		size;
	char	*solution;
	char	*selstr;
	char	*ascent;
	char	*str;

	size = ft_psllength(ablist[0]);
	solution = ft_strnew(10000);
	if (size && solution)
	{
		ascent = ft_find_best_ascent(ablist);
		ft_selstr_invert(ascent);
		selstr = ft_halfsel_by_dest(ablist, size, ascent, 1);
		str = ft_osift_multi(ablist, size, 0, selstr, 2);
		ft_apply_moves(ablist, str);
		ft_strcat(solution, str);
		ft_strdel_plus(&str);
		ascent = ft_find_best_ascent(ablist);
		ft_selstr_invert(ascent);
		selstr = ft_halfsel_by_dest(ablist, size, ascent, 1);
		printf("second ascent : %s\n", selstr);
		getchar();
		str = ft_osift_multi(ablist, size, 0, selstr, 2);
		printf("second sifting : %s\n", str);
		ft_strcat(solution, str);
		getchar();
//		ft_strdel_plus(&str);
		ft_apply_moves(ablist, str);
		ascent = ft_find_best_ascent(ablist);
		ft_selstr_invert(ascent);
		printf("second ascent : %s\n", ascent);
		str = ft_osift_multi(ablist, size, 0, ascent, 2);
		printf("third sifting : %s\n", str);
		getchar();
		ft_apply_moves(ablist, str);
		ft_strcat(solution, str);
		while(ft_psllength(ablist[1]))
		{
			str = ft_merge_descent(ablist, size);//ft_merge_ordered(ablist, size);
			ft_pslprint(ablist);
			getchar();
			ft_strcat(solution, str);
		}
		printf("solution is now %s\n\n %zu OPERATIONS!\n", solution, ft_strlen(solution));
		getchar();
	}
	return (solution);
}

void	ft_ps_solve(t_pscell **ablist)
{
	char	*solution;

	solution = NULL;
	if (ablist)
	{
		ft_find_correct_positions(ablist);
		if (ft_done(ablist))
			ft_printf("\n");
		else
		{
			if (ft_psllength(ablist[0]) < 16)
				solution = ft_smallsolve(ablist);
			else
				solution = ft_bigsolve(ablist);
//			printf("solution is %s\n", solution);
			ft_expand_print(solution);
			ft_strdel_plus(&solution);
		}
	}
}

int		main(int argc, char **argv)
{
	char		*input;
	char		*moves;
	t_pscell	*ablist[3];

	moves = NULL;
	ft_bzero(ablist, sizeof(t_pscell*) * 3);
	input = NULL;
	if (argc == 2)
	{
		input = ft_strdup(argv[1]);
		if (input)
		{
			if (!ft_readin(ablist, input))
				ft_printf("Error\n");
			else
				ft_ps_solve(ablist);
			ft_strdel_plus(&input);
		}
	}
	return (1);
}
