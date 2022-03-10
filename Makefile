HEADER := include/push_swap.h

LIBFT = libft/libft.a
CC := clang

TestingFlags := -fsanitize=address

FLAGS := -Wall -Wextra -Werror -I./include -g3 -ggdb3

PUSH_SWAP := push_swap

SRC_PUSH_SWAP = main.c  \
				subsequence_opt/subsequence.c subsequence_opt/marking_seq.c \
				utils/input_handler.c utils/output_utils.c utils/debug_output.c\
				utils/lst_utils.c utils/lst_adds_n_pops.c utils/ft_atoi_modded.c utils/utils.c \
				operations/swap_push.c operations/rotating.c operations/reverse_rotating.c \
				sorting/sorting.c sorting/presorting.c sorting/score_marking.c  sorting/resulting_score.c \
				sorting/small_sort.c sorting/push_to_b.c \

SRC_CHECKER =   checker.c\
				utils/input_handler.c utils/output_utils.c utils/debug_output.c \
				utils/lst_utils.c utils/lst_adds_n_pops.c utils/ft_atoi_modded.c utils/utils.c \
				operations/swap_push.c operations/rotating.c operations/reverse_rotating.c \
				sorting/sorting.c sorting/presorting.c sorting/score_marking.c  sorting/resulting_score.c \
				sorting/small_sort.c

OBJ_DIR = ./obj/
SRC_DIR = ./src/

SRC_FILES_PUSH_SWAP = $(addprefix $(SRC_DIR), $(SRC_PUSH_SWAP))
SRC_FILES_CHECKER = $(addprefix $(SRC_DIR), $(SRC_CHECKER))

OBJ_FILES_PUSH_SWAP = $(addprefix $(OBJ_DIR), $(SRC_PUSH_SWAP))
OBJ_PUSH_SWAP = $(patsubst %.c, %.o, $(OBJ_FILES_PUSH_SWAP))

OBJ_FILES_CHECKER = $(addprefix $(OBJ_DIR), $(SRC_CHECKER))
OBJ_CHECKER = $(patsubst %.c, %.o, $(OBJ_FILES_CHECKER))

RM := rm -rf

CHECKER = checker

all: $(OBJ_DIR) $(HEADER) $(PUSH_SWAP)

$(PUSH_SWAP): $(HEADER) $(OBJ_PUSH_SWAP)
	$(CC) $(OBJ_PUSH_SWAP) -o $(PUSH_SWAP)

$(LIBFT) :
	make -C ./libft

bonus : $(all) $(OBJ_DIR) $(CHECKER)

$(CHECKER) : $(HEADER) $(OBJ_DIR) $(OBJ_CHECKER)
	$(CC) $(OBJ_CHECKER) -o $(CHECKER)

#%.o: %.c $(HEADER)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir obj
	mkdir obj/utils
	mkdir obj/operations
	mkdir obj/sorting
	mkdir obj/subsequence_opt


clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(PUSH_SWAP)
	$(RM) $(CHECKER)
#ALSO NEED TO CLEAN libft
re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus
