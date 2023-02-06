NAME := libftprintf.a
SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_putpointer.c \
		ft_putstr.c \
		ft_putunsigned.c \
		ft_putsigned.c \
		ft_puthex.c \
		ft_strlen.c

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
PATH_OBJS = $(addprefix $(OBJS_DIR),$(OBJS))
B_OBJS = $(B_SRCS:.c=.o)
PATH_B_OBJS = $(addprefix $(OBJS_DIR),$(B_OBJS))
HEAD := ft_printf.h
CC := cc
CFLAGS := -Wall -Wextra -Werror

$(NAME): $(PATH_OBJS)
	@ar rc $(NAME) $(PATH_OBJS)
	@echo "libft done"

all: $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@
	@echo "Compiling $(<)"

bonus: $(PATH_B_OBJS)
	@ar rc $(NAME) $(PATH_B_OBJS)
	@echo "libft bonus part was done"

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re