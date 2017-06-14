/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:29:32 by adaly             #+#    #+#             */
/*   Updated: 2017/06/14 05:10:00 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libftprintf/libft.h"

typedef struct			s_pscell
{
	char				list;
	intmax_t			value;
	uintmax_t			current;
	uintmax_t			correct;
	struct s_pscell		*next;
}						t_pscell;

uintmax_t	ft_pslsize(t_pscell *list);
void	ft_swap_a(t_pscell **ablist);
void	ft_swap_b(t_pscell **ablist);
void	ft_swap_ab(t_pscell **ablist);
void	ft_shift_up(t_pscell **ablist, char aorb, uintmax_t size);
void	ft_shift_down(t_pscell **ablist, char aorb, uintmax_t size);
void	ft_rotate_ab(t_pscell **ablist, uintmax_t asize, uintmax_t bsize);
void	ft_rotate_a(t_pscell **ablist, uintmax_t asize);
void	ft_rotate_b(t_pscell **ablist, uintmax_t bsize);
void	ft_revrotate_ab(t_pscell **ablist, uintmax_t asize, uintmax_t bsize);
void	ft_revrotate_a(t_pscell **ablist, uintmax_t asize);
void	ft_revrotate_b(t_pscell **ablist, uintmax_t bsize);
void	ft_push_a(t_pscell **ablist, uintmax_t asize);
void	ft_push_b(t_pscell **ablist, uintmax_t bsize);
void	ft_psczero(t_pscell *target);
char	**ft_generate_moves(uintmax_t depth);
t_pscell	**ft_psldup(t_pscell **ablist, uintmax_t size);
t_pscell	**ft_apply_moves(t_pscell **input_list, char *str, uintmax_t size);


