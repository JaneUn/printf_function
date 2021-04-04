NAME	=	libft.a

INC		=	libft.h

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_utoa.c \
		ft_putnchar.c \
		ft_memalloc.c

BONUS_S	=	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c

OBJS	=	$(SRCS:.c=.o)

BONUS_O	=	$(BONUS_S:.c=.o)

.PHONY:	all clean fclean re

all:	$(NAME)

%.o:	%.c	$(INC)
	@gcc $(FLAGS) -c $<

$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus:	$(BONUS_O)
	@ar rcs $(NAME) $(BONUS_O)

clean:
	@rm -f $(OBJS) $(BONUS_O)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
