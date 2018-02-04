/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:03:55 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 23:09:02 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

void		ft_selstr_rot(char *str)
{
	char	*temp;

	temp = NULL;
	if (str)
	{
		temp = ft_strdup(str);
		if (temp)
		{
			ft_strncpy(str, temp + 1, ft_strlen(temp) - 1);
			str[ft_strlen(temp) - 1] = temp[0];
			ft_bzero(temp, ft_strlen(temp));
			free(temp);
		}
	}
}

void		ft_selstr_revrot(char *str)
{
	char	*temp;

	temp = NULL;
	if (str)
	{
		temp = ft_strdup(str);
		if (temp)
		{
			ft_strncpy(str + 1, temp, ft_strlen(temp) - 1);
			str[0] = temp[ft_strlen(temp) - 1];
			ft_bzero(temp, ft_strlen(temp));
			free(temp);
		}
	}
}

void		ft_selstr_push(char *from, char *to)
{
	char	*temp;

	temp = NULL;
	if (from && to)
	{
		temp = ft_strdup(to);
		if (temp)
		{
			to[0] = from[0];
			ft_strcpy(to + 1, temp);
			ft_bzero(temp, ft_strlen(temp));
			free(temp);
		}
		temp = ft_strdup(from + 1);
		if (temp)
		{
			ft_bzero(from, ft_strlen(from));
			ft_strcpy(from, temp);
			ft_bzero(temp, ft_strlen(temp));
			free(temp);
		}
	}
}

static intmax_t	ft_first_viable_selstr(t_pscell **ablist, int which_list, uintmax_t correct, char *selstr)
{
	intmax_t	first;
	intmax_t	remainder;
	uintmax_t	length;

	length = ft_psllength(ablist[which_list]);
	first = ft_sifting_sedge(ablist, which_list, selstr);
//	printf("first is %ji, length is %ju\n", first, length);
//	printf("correct is %ju\n", correct);
//	getchar();
	remainder = first;
//	printf("remainder is %ji\n", remainder);
//	printf("first viable selstr is %s\n", selstr);
//	if (correct > (first ? ablist[which_list][first - 1].correct : ablist[which_list][length - 1].correct))
//		return (first);
//	if (!correct && first >= 0)
//		return ((first < (length - 1)) ? (first + 1) : 0);
	while (first < (intmax_t)length)
	{
//		if (selstr[first] == '1')
//			printf("%ju > %ju?\n", correct, ablist[which_list][first].correct);
		if (correct > ablist[which_list][first].correct && (selstr[first] == '1'))// || selstr[first + 1] == '1' || selstr[first - 1] == '1'))
			return (first);
		++first;
	}
	if (remainder)
		first = 0;
//	printf("remainder is %ji\n", remainder);
	while (first < remainder)
	{
//		if (selstr[first] == '1')
//			printf("%ju > %ju?\n", correct, ablist[which_list][first].correct);
		if (correct > ablist[which_list][first].correct && selstr[first] == '1')// && (selstr[first] == '1' || selstr[first + 1] == '1' || selstr[first - 1] == '1'))
			return (first);
		++first;
	}
	first = ft_sifting_sedge(ablist, which_list, selstr);
	if (selstr[first] == '1')
		return (first);
//	getchar();
	return (-1);
}

intmax_t	ft_find_right_spot_selstr(t_pscell **ablist, uintmax_t size, intmax_t element, char *selstr)
{
	int			which_list;
	uintmax_t	index;
	uintmax_t	correct_spot;
	intmax_t	first_viable;

	first_viable = -1;
	if (ablist && size && selstr)
	{
	first_viable = -1;
	index = element ? ft_absval(element) - 1 : 0;
	which_list = ((element < 0) ? 1 : 0);
	if (ft_psllength(ablist[which_list ? 0 : 1]) < 2)
		return (0);
	if (selstr && ablist && index < ft_psllength(ablist[which_list ? 1 : 0]))
	{
//		printf("hello\n");
		correct_spot = ablist[which_list][index].correct;
//		printf("correct is %ju\n", correct_spot);
		first_viable = ft_first_viable_selstr(ablist, which_list ? 0 : 1, correct_spot, selstr);
	}
//		printf("first viable is %ji\n", first_viable);
	}
	return (first_viable);
}

char	*ft_find_final_spot(t_pscell **ablist, intmax_t element, char *selstr)
{
	intmax_t	ret;
	int			index;
	intmax_t	first;
	uintmax_t	length;
	char		*best;

	best = NULL;
	ret = -1;
	length = ft_psllength(ablist[1]);
	index = ft_absval(element) - 1;
	first = ft_sifting_sedge(ablist, 1, selstr);
//	printf("selstr is %s\n", selstr);
//	printf("first is %ji\n, element is %ji\n", first, element);
	if (ablist[0][index].correct == 0)
	{
		ret = first;
//		ret = ((first < (length - 1)) ? (first + 1) : 0);
		best = ft_speed_surfacing(ablist, index, ret);
		best[ft_strlen(best)] = '2';
//		printf("best is %s\n", best);
//		getchar();
	}
	else
	{
		ret = ft_find_right_spot_selstr(ablist, ft_psllength(ablist[0]) + ft_psllength(ablist[1]), element, selstr);
		best = ft_speed_surfacing(ablist, index, ret);
		best[ft_strlen(best)] = '2';
	}
	return (best);
}
