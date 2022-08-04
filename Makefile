SRCS =  main.c \
	srcs/ft_strlen.c \
	srcs/ft_memcpy.c \
	srcs/ft_strcmp.c \
	srcs/ft_putstr.c

OBJS	= ${SRCS:.c=.o}
CC	= gcc
CCFLAGS	= -Wall -Wextra
NAME	= libft

.PHONY: all clean fclean re

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

all : $(NAME)

clean :
	-rm -f $(OBJS)

fclean : clean
	-rm -f $(NAME)

re : fclean all
