NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

BONUS = checker

SRC = main.c \
	parsing/arguments_check.c \
	parsing/libft_mini.c \
	parsing/libft_mini2.c \
	parsing/libft_mini3.c \
	parsing/ft_split.c \
	parsing/free.c \
	stack_moves/stack_creation.c \
	stack_moves/instructions.c \
	small_num/sort_2_3_5.c \
	sorting/push_a_to_b.c \
	sorting/sort_b_to_a.c \
	sorting/b_to_a_utils.c \
	sorting/a_to_b_utils.c \

SRCB = checker_f/main.c \
	checker_f/gnl/get_next_line.c \
	checker_f/gnl/get_next_line_utils.c \
	stack_moves/stack_creation.c \
	stack_moves/instructions.c \
	parsing/arguments_check.c \
	parsing/libft_mini.c \
	parsing/libft_mini2.c \
	parsing/libft_mini3.c \
	parsing/ft_split.c \
	parsing/free.c \
	

OBJS = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) push_swap.h
	@$(CC) $(CFLAGS) $(OBJS) -o $@

bonus : $(BONUS)

$(BONUS) : $(OBJB) checker_f/checker.h
	@$(CC) $(CFLAGS) $(OBJB) -o $@

clean :
	@rm -f $(OBJS) $(OBJB)

fclean : clean
	@rm -f $(NAME) $(BONUS)

re : fclean all