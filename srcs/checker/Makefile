NAME= checker

SRCS=	checker.c \
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
		ft_shift.c

OBJS = $(SRCS:.c=.o)

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS)
	gcc $(FLAGS) $(OBJS) ../libftprintf/libftprintf.a -o $(NAME)

clean:
	rm -f $(OBJS)
