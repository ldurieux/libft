SRCS = main.c
OBJS = ${SRCS:.c=.o}
CC = gcc
ifeq ($(OS), Windows_NT)
	CCFLAGS = -Wall -Wextra
else
	CCFLAGS = -Wall -Wextra -fsanitize=address -g3
endif
NAME = libft

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
