HEADER := include/push_swap.h

LIBFT = libft/libft.a
CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Wextra -Werror -Imlx -I./include -g3 -I./libft/include
PUSH_SWAP := push_swap

SRC_FILES_PUSH_SWAP = $(addprefix src/, push_swap.c input_handler.c)

OBJ_PUSH_SWAP = $(patsubst %.c, %.o, $(SRC_FILES_PUSH_SWAP))
OBJ_CHECKER = $(patsubst %.c, %.o, $(SRC_FILES_CHECKER))

RM := rm -rf

all: $(LIBFT) $(HEADER) $(PUSH_SWAP) $(OBJ)

$(PUSH_SWAP): $(LIBFT) $(OBJ_PUSH_SWAP) $(HEADER)
	$(CC) $(OBJ_PUSH_SWAP) $(LIBFT) $(FT_PRINTF) -o $(PUSH_SWAP)

$(LIBFT) :
	make -C ./libft

bonus : $(all)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PUSH_SWAP)
	make -C ./libft clean
fclean: clean
	$(RM) $(PUSH_SWAP)
	make -C ./libft fclean
#ALSO NEED TO CLEAN libft
re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus
