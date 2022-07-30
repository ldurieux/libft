SRCS =  main.c \
        srcs/ft_strlen.c

OBJS	= ${SRCS:.c=.o}
CC	= gcc
CCFLAGS	= -Wall -Wextra
ifeq ($(OS), Windows_NT)
	CCSANITIZE = 
else
        CCSANITIZE = -fsanitize=address -g3
endif
NAME	= libft

.PHONY: all clean fclean re

srcs/ft_str_utils.o : srcs/ft_str_utils.c
	$(CC) $(CCFLAGS) -c $< -o $@

%.o : %.c
	$(CC) $(CCSANITIZE) $(CCFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	$(CC) $(CCSANITIZE) $(CCFLAGS) -o $@ $^

all : $(NAME)

clean :
	-rm -f $(OBJS)
	
fclean : clean
	-rm -f $(NAME)
	
re : fclean all
