SRCS =  main.c \
	srcs/ft_strlen.c

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
