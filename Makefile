NAME            = push_swap
NAME_BONS       = checker
CC              = cc
CFLAGS          = -Wall -Wextra -Werror
LIBFT           =  ./Libft/libft.a
HEADER          = ./Mandatory/push_swap.h
HEADER_BONS = ./Bonus/push_swap_bonus.h

SRCS            = ./Mandatory/push_swap.c				\
				./Mandatory/src/manipulate_stack.c	\
				./Mandatory/src/handle_arguments.c	\
				./Mandatory/src/push.c				\
				./Mandatory/src/rotate.c				\
				./Mandatory/src/sort_funcs.c			\
				./Mandatory/src/sort_tools.c			\
				./Mandatory/src/sort.c				\
				./Mandatory/src/stack_tools.c			\
				./Mandatory/src/handle_arg_tools.c

SRCS_BONS		= ./Bonus/push_swap.c					\
				./Bonus/src/manipulate_stack.c			\
				./Bonus/src/handle_arguments.c			\
				./Bonus/src/push.c						\
				./Bonus/src/rotate.c					\
				./Bonus/src/sort_funcs.c				\
				./Bonus/src/sort_tools.c				\
				./Bonus/src/sort.c						\
				./Bonus/src/stack_tools.c				\
				./Bonus/src/handle_arg_tools.c			\
				./get_next_line/get_next_line.c			\
				./get_next_line/get_next_line_utils.c


OBJS = $(SRCS:.c=.o)
OBJS_BONS = $(SRCS_BONS:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

all: libft $(NAME)

bonus: libft $(NAME_BONS)

$(NAME) : $(OBJS) $(LIBFT) 
		$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $@

$(NAME_BONS): $(OBJS_BONS) $(OBJS_GNL) $(LIBFT)
		$(CC) $(CFLAGS) $(LIBFT) $(OBJS_BONS) -o $@

libft:
		make -C Libft

# %_bonus.o: %_bonus.c $(HEADER_BONS)
# 		$(CC) $(CFLAGS) -c $< -o $@

%.o:%.c $(HEADER) $(LIBFT)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		make -C Libft clean

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

.PHONY: all bonus libft clean fclean re