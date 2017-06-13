/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:29:32 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 05:09:32 by adaly            ###   ########.fr       */
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
