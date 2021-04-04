NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./ft_printf.c ./utils.c\
			  ./check_flag.c ./check_prec.c ./check_spec.c\
			  ./check_width.c ./print_char.c ./print_hex.c\
			  ./print_int.c ./print_percent.c ./print_ptr.c\
			  ./print_string.c ./print_unsigned.c
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	@make all -C $(LIBFT)/
	@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	@$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)

clean :
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT)

re : fclean all
