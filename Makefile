NAME            = push_swap
NAME_BONS       = push_swap_bonus
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

# SRCS_BONS       = ./Bonus/src/handle_map_bonus.c                \
#                          ./Bonus/src/check_map_bonus.c            \
#                          ./Bonus/src/animation_bonus.c            \
#                          ./Bonus/src/enemy_bonus.c                \
#                          ./Bonus/src/print_sprites_bonus.c        \
#                          ./Bonus/src/init_data_bonus.c            \
#                          ./Bonus/src/check_valid_path_bonus.c   \
#                          ./Bonus/src/check_functions_bonus.c    \
#                          ./Bonus/push_swap_bonus.c

OBJS = $(SRCS:.c=.o)
# OBJS_BONS = $(SRCS_BONS:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

all: libft $(NAME)

bonus: libft $(NAME_BONS)

$(NAME) : $(OBJS) $(LIBFT) 
		$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $@

# $(NAME_BONS): $(OBJS_BONS) $(OBJS_GNL) $(LIBFT)
#         @echo "Building the game.."
#         @$(CC) $(CFLAGS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit  $(OBJS_BONS) $(OBJS_GNL) -o $(NAME_BONS)

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