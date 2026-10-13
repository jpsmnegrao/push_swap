NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCES = push_swap.c ft_atoi.c ft_calloc.c ft_check_dups.c ft_error.c \
	ft_free_arrays.c ft_free_split.c ft_isdigit.c ft_memcpy.c \
	ft_parse_input.c ft_split.c ft_strlcpy.c ft_strlen.c \
	op_push.c op_rev_rotate.c op_rotate.c op_swap.c sorting_utils.c \
	sort_small.c sort_large.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
