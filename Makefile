HEADER := include/push_swap.h

LIBFT = libft/libft.a
CC := clang

TestingFlags := -fsanitize=address

FLAGS := -Wall -Wextra -Werror -Imlx -I./include -g3 -I./libft/include
PUSH_SWAP := push_swap

SRC_FILES_PUSH_SWAP = $(addprefix src/, push_swap.c input_handler.c output_utils.c \
						lst_utils.c ft_atoi_modded.c \
						operations_swap_push.c operations_rotating.c operations_reverse_rotating.c)

OBJ_PUSH_SWAP = $(patsubst %.c, %.o, $(SRC_FILES_PUSH_SWAP))
OBJ_CHECKER = $(patsubst %.c, %.o, $(SRC_FILES_CHECKER))

RM := rm -rf

all: $(HEADER) $(PUSH_SWAP) $(OBJ)

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(HEADER)
	$(CC) $(OBJ_PUSH_SWAP) -o $(PUSH_SWAP)

$(LIBFT) :
	make -C ./libft

bonus : $(all)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PUSH_SWAP)
fclean: clean
	$(RM) $(PUSH_SWAP)
#ALSO NEED TO CLEAN libft
re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus
