NAME			= push_swap
NAME_BONS		= checker
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_LIB		=  ./Libft/libft.a
HEADER			= ./Mandatory/push_swap.h
HEADER_BONS 	= ./Bonus/checker_bonus.h
HEADER_GNL		= ./get_next_line/get_next_line.h

SRCS			= ./Mandatory/main.c					\
				./Mandatory/src/manipulate_stack.c		\
				./Mandatory/src/handle_arguments.c		\
				./Mandatory/src/push.c					\
				./Mandatory/src/rotate.c				\
				./Mandatory/src/rev_rotate.c			\
				./Mandatory/src/sort_tools.c			\
				./Mandatory/src/sort.c					\
				./Mandatory/src/swap.c					\
				./Mandatory/src/stack_tools.c			\
				./Mandatory/src/handle_arg_tools.c

SRCS_BONS		= ./Bonus/main_bonus.c					\
				./Bonus/src/manipulate_stack_bonus.c	\
				./Bonus/src/handle_arguments_bonus.c	\
				./Bonus/src/push_bonus.c				\
				./Bonus/src/rotate_bonus.c				\
				./Bonus/src/swap_bonus.c				\
				./Bonus/src/rev_rotate_bonus.c			\
				./Bonus/src/stack_tools_bonus.c			\
				./Bonus/src/handle_arg_tools_bonus.c

SRCS_GNL		= ./get_next_line/get_next_line.c		\
				./get_next_line/get_next_line_utils.c


OBJS = $(SRCS:.c=.o)
OBJS_BONS = $(SRCS_BONS:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

all: libft $(NAME)

bonus: libft $(NAME_BONS)

$(NAME) : $(OBJS) $(LIBFT_LIB)
	@echo "Building $@"
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJS) -o $@

$(NAME_BONS): $(OBJS_BONS) $(OBJS_GNL) $(LIBFT_LIB)
	@echo "Building $@"
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJS_BONS) $(OBJS_GNL) -o $@

libft:
	@make -C Libft

get_next_line/%.o: get_next_line/%.c $(HEADER_GNL)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER_BONS) $(OBJS_GNL) $(LIBFT_LIB)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o:%.c $(HEADER) $(LIBFT_LIB)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removed object files"
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONS)
	@rm -f $(OBJS_GNL)
	@make -C Libft clean

fclean: clean
	@echo "Removed executable"
	@echo "Libft library removed"
	@rm -f $(NAME)
	@rm -f $(NAME_BONS)
	@rm -f $(LIBFT_LIB)

re: fclean all

.PHONY: all bonus libft clean fclean re