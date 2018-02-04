NAME=pushswap

all: $(NAME)

$(NAME):
	make -C srcs/libftprintf
	make -C srcs/push_swap
	make -C srcs/checker
	mv srcs/push_swap/push_swap .
	mv srcs/checker/checker .

clean:
	make -C srcs/libftprintf clean
	make -C srcs/push_swap clean
	make -C srcs/checker clean

fclean: clean
	rm -f push_swap checker

re: fclean all
