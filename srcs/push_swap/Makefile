NAME= push_swap

SRCS=	push_swap.c \
		ft_psllength.c \
		ft_readin.c \
		ft_presort.c \
		ft_apply_moves.c \
		ft_done.c \
		ft_push.c \
		ft_swap.c \
		ft_rotate.c \
		ft_revrotate.c \
		ft_io.c \
		ft_pscell.c \
		ft_pslprint.c \
		ft_shift.c \
		ft_merge.c \
		ft_final_round.c \
		ft_how_many_rots.c \
		ft_identify.c \
		ft_osift_beta.c \
		ft_sifting_a.c \
		ft_sifting_b.c \
		ft_uintmax_choose.c \
		ft_psldup.c \
		ft_ordered_sift.c \
		ft_pslfind.c \
		ft_selstr.c \
		ft_intmerge.c \
		ft_test.c \
		ft_select_in_order.c \
		ft_opush_select.c

OBJS = $(SRCS:.c=.o)

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS)
	gcc $(FLAGS) $(OBJS) ../libftprintf/libftprintf.a -o $(NAME)

clean:
	rm -f $(OBJS)
