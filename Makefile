NAME = push_swap.a
SOURCES = push_swap.c ft_atoi.c ft_isdigit.c
BONUS = 
OBJS = $(SOURCES:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

bonus : .bonus

.bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) .bonus

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:
	all clean fclean re bonus
