NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCES = push_swap.c ft_atoi.c ft_calloc.c ft_check_dups.c ft_error.c ft_free_split.c /
		ft_isdigit.c ft_memcpy.c ft_parse_input.c ft_split.c ft_strlcpy.c ft_strlen.c /
		op_push.c op_rev_rotate.c op_rotate.c op_swap.c

OBJS = $(SOURCES:.c=.o)

DEBUG = debug_utils.c
DEBUG_OBJS = $(DEBUG:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(DEBUG_OBJS)
	$(CC) $(OBJS) $(DEBUG_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEBUG_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) push_swap

re: fclean all

.PHONY:
	all clean fclean re

# ft_atoi.c
# ft_calloc.c
# ft_check_dups.c
# ft_error.c
# ft_free_split.c
# ft_isdigit.c
# ft_memcpy.c
# ft_parse_input.c
# ft_split.c
# ft_strlcpy.c
# ft_strlen.c
# op_push.c
# op_rev_rotate.c
# op_rotate.c
# op_swap.c
# push_swap.c
