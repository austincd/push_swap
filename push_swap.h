/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:29:32 by adaly             #+#    #+#             */
/*   Updated: 2017/10/05 07:27:43 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "srcs/libftprintf/libft.h"
#include "srcs/libftprintf/ft_printf.h"

typedef struct			s_quadi
{
	intmax_t			a;
	intmax_t			b;
	intmax_t			c;
	intmax_t			d;
}						t_quadi;

typedef struct			s_pscell
{
	char				list;
	char				active;
	char				locked;
	intmax_t			value;
	uintmax_t			current;
	uintmax_t			correct;
}						t_pscell;

char		*ft_final_round(t_pscell **ablist, uintmax_t size);
void		ft_expand_print(char *movelist);
char		*ft_find_best_ascent(t_pscell **ablist);
int			ft_done(t_pscell **ablist);
char		*ft_contract(int fd);
char		*ft_halfsel_by_dest(t_pscell **ablist, uintmax_t size, char *selstr, char which_half);
char		*ft_merge_descent(t_pscell **ablist, uintmax_t size);
char	*ft_merge_ordered(t_pscell **ablist, uintmax_t size);
char	*ft_find_final_spot(t_pscell **ablist, intmax_t element, char *selstr);
char	*ft_osift_multi(t_pscell **ablist, uintmax_t size, int which_list, char *to_remove, int factor);
void	ft_selstr_invert(char *selstr);
char	*ft_osift_beta(t_pscell **ablist, uintmax_t size, int which_list, char *to_remove);
intmax_t	ft_sifting_sedge(t_pscell **ablist, int which_list, char *selstr);
intmax_t	ft_orderedpushselstr(t_pscell **ablist, uintmax_t size, uintmax_t radius, int which_list, char *selstr, char *placement);
void		ft_selstr_rot(char *str);
void		ft_selstr_revrot(char *str);
void		ft_selstr_push(char *str, char *stro);
intmax_t	ft_find_right_spot_selstr(t_pscell **ablist, uintmax_t size, intmax_t element, char *selstr);

int		**ft_integerize(t_pscell **ablist, uintmax_t size, int *lengths);
char	*ft_best_ascent(uintmax_t length, char **ascents, uintmax_t *counts);
uintmax_t	ft_jusel_highest(uintmax_t *elements, uintmax_t *locations, uintmax_t *bounds, char *selstr);
uintmax_t	*ft_count_ascent(t_pscell **ablist, uintmax_t size, int which_list, char **ascents);
char	*ft_identify_bymin(t_pscell **ablist, uintmax_t size, int which_list, uintmax_t min);
char	**ft_identify_ascent(t_pscell **ablist, uintmax_t size, int which_list);
void	ft_opush_select(t_pscell **ablist, uintmax_t size, intmax_t *locations, intmax_t *bests);
char	*ft_speed_surfacing(t_pscell **ablist, uintmax_t alpha, uintmax_t beta);
char	*ft_ordered_sift(t_pscell **ablist, uintmax_t size, int which_list);
char	*ft_iteration_osift(t_pscell **ablist, uintmax_t size, int which_list);
intmax_t    ft_orderedpush(t_pscell **ablist, uintmax_t size, uintmax_t radius, int which_list);
intmax_t    ft_find_right_spot(t_pscell **ablist, intmax_t element);
intmax_t    ft_sifting_edge(t_pscell **ablist, int which_list);
char	*ft_identify_unlocked(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_iteration_makesallsegsadj(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_make_allsegs_adjacent(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_makesegsadj_str(uintmax_t *pairs, uintmax_t segmentlen, char pushto);
char    *ft_make_oneseg_adjacent(t_pscell **ablist, uintmax_t size, uintmax_t seglength, intmax_t element);
char    *ft_pushbackseg(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_selectsegs_length(uintmax_t *seglengths, intmax_t filter);
char*ft_pushbyseg(uintmax_t *seglengths, char *selection, char *moves, char *map);
uintmax_t   *ft_seglengths(char *str);
char    *ft_identify_tails(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_identify_heads(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_make_all_adjacent(t_pscell **ablist, uintmax_t size, int which_list);
char	*ft_iteration_makeadj(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_makeadj_str(uintmax_t *pairs, char pushto);
char    *ft_make_one_adjacent(t_pscell **ablist, uintmax_t size, intmax_t element);
uintmax_t   ft_how_many_rots(uintmax_t element, uintmax_t destination, uintmax_t length);
uintmax_t   ft_how_many_revrots(uintmax_t element, uintmax_t destination, uintmax_t length);
char    *ft_pushall(t_pscell **ablist, uintmax_t size);

void    ft_parse_basic_return(char *str, int which_list);
intmax_t    *ft_howmuchdideachthingmove(intmax_t *alpha, intmax_t *beta, uintmax_t num_elements);
void    ft_ptrsort(void **array, intmax_t *unsorted_values, uintmax_t num_values, uintmax_t num_bytes);

void    ft_lock(t_pscell **ablist, uintmax_t size, intmax_t element);
char	**ft_generate_moveapp(char *str, char icot, char icof);

char    *ft_siftout_oops(t_pscell **ablist, uintmax_t size, int which_list);
char    *ft_sift_oops(t_pscell **ablist, uintmax_t size, int which_list);

char        *ft_basic_sift(t_pscell **ablist, uintmax_t size, char phase);
char        *ft_basic_replace(t_pscell **ablist, uintmax_t size);
char    *ft_basic(intmax_t *list, uintmax_t size);
char		*ft_cycles_b(intmax_t   **adjacents);
intmax_t	*ft_locate_adjacents(t_pscell **ablist, uintmax_t size, int which_list, uintmax_t index);
char	*ft_correct_sorting_adjacents(intmax_t **adjacents);

char	*ft_identify_oops(t_pscell **ablist, uintmax_t size, int which_list);
char **ft_dynamic_sets(t_pscell ***ablist, uintmax_t size);
char    **ft_dynamic_swap(t_pscell **ablist, uintmax_t size, char aorb);

uintmax_t	ft_scoreone_placement(t_pscell **ablist, uintmax_t size, uintmax_t index, char aorb);
uintmax_t	ft_scoreone_proximity(t_pscell **ablist, uintmax_t size, uintmax_t index, char aorb);
uintmax_t	ft_scoreone(t_pscell **ablist, uintmax_t size, uintmax_t index, char aorb);

uintmax_t	*ft_identify_segments(t_pscell **ablist, uintmax_t size);
char		**ft_segments(uintmax_t *segments, uintmax_t size);
void		ft_push_segments(char **dst, uintmax_t *segments, uintmax_t num_segs, uintmax_t *order);
void		ft_push_segment(char **dst, uintmax_t *segments, uintmax_t num_segs, uintmax_t which_segment);

uintmax_t   **ft_ordergen(uintmax_t num_values);
void        ft_permuteju(uintmax_t **output, uintmax_t *array, uintmax_t start, uintmax_t end);
void        ft_swapju(uintmax_t *x, uintmax_t *y);

char		**ft_switch_a(uintmax_t size);
char		**ft_switch_b(uintmax_t size);
char		**ft_pushes(uintmax_t size);
char		**ft_rotations(uintmax_t size);
char		**ft_shuffle(uintmax_t size);
char		**ft_generate_mini(uintmax_t depth);

char		*ft_solve(t_pscell ***ablist, uintmax_t size);
uintmax_t	ft_iterate(t_pscell ***ablist, uintmax_t size, char **moveset, char **solution);
uintmax_t	ft_score(t_pscell **ablist, uintmax_t size);
uintmax_t	ft_pslcheck(t_pscell **ablist, uintmax_t size);
uintmax_t	ft_psllength(t_pscell *list);
void	ft_swap_a(t_pscell **ablist);
void	ft_swap_b(t_pscell **ablist);
void	ft_swap_ab(t_pscell **ablist);
void	ft_shift_up(t_pscell **ablist, char aorb);
void	ft_shift_down(t_pscell **ablist, char aorb);
void	ft_rotate_ab(t_pscell **ablist);
void	ft_rotate_a(t_pscell **ablist);
void	ft_rotate_b(t_pscell **ablist);
void	ft_revrotate_ab(t_pscell **ablist);
void	ft_revrotate_a(t_pscell **ablist);
void	ft_revrotate_b(t_pscell **ablist);
void	ft_push_a(t_pscell **ablist);
void	ft_push_b(t_pscell **ablist);
void	ft_psczero(t_pscell *target);
char	**ft_generate_moves(uintmax_t depth);
char	**ft_generate_patterns(uintmax_t size);
t_pscell	**ft_psldup(t_pscell **ablist, uintmax_t size);
t_pscell	**ft_apply_moves(t_pscell **input_list, char *str);
intmax_t	*ft_presort(intmax_t *list, uintmax_t length);
void		ft_record_correct_sorting(t_pscell **ablist, intmax_t *correct, uintmax_t size);
void		ft_find_correct_positions(t_pscell **ablist);
void		ft_pslprint(t_pscell **ablist);
int				ft_readin(t_pscell **ablist, char *input);
void			ft_pslcpy(t_pscell *src, t_pscell *dst, uintmax_t size);
void			ft_ablist_cpy(t_pscell **src, t_pscell **dst, uintmax_t size);
uintmax_t		ft_proximity(t_pscell **ablist, intmax_t alpha, intmax_t beta);
intmax_t		ft_pslfind(t_pscell **ablist, uintmax_t value);
void			ft_increment_values(uintmax_t *nums, uintmax_t *limits);
