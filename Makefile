HEADER := include/push_swap.h

LIBFT = libft/libft.a
CC := clang

TestingFlags := -fsanitize=address

FLAGS := -Wall -Wextra -Werror -I./include -g3
PUSH_SWAP := push_swap

SRC_PUSH_SWAP = main.c input_handler.c output_utils.c \
				lst_utils.c lst_adds_n_pops.c ft_atoi_modded.c \
				operations_swap_push.c operations_rotating.c operations_reverse_rotating.c \
				sorting.c presorting.c score_marking.c

OBJ_DIR = ./obj/
SRC_DIR = ./src/

SRC_FILES_PUSH_SWAP = $(addprefix $(SRC_FIR), $(SRC_PUSH_SWAP))
OBJ_FILES_PUSH_SWAP = $(addprefix $(OBJ_DIR), $(SRC_PUSH_SWAP))
OBJ_PUSH_SWAP = $(patsubst %.c, %.o, $(OBJ_FILES_PUSH_SWAP))
OBJ_CHECKER = $(patsubst %.c, %.o, $(SRC_FILES_CHECKER))

RM := rm -rf

all: $(OBJ_DIR) $(HEADER) $(PUSH_SWAP) $(OBJ)

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(HEADER)
	$(CC) $(OBJ_PUSH_SWAP) -o $(PUSH_SWAP)

$(LIBFT) :
	make -C ./libft


bonus : $(all)

#%.o: %.c $(HEADER)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir obj

clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(PUSH_SWAP)
#ALSO NEED TO CLEAN libft
re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus
