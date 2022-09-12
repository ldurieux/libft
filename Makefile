NAME		= libft.a

SRCS		= \
			  srcs/ft_strlen.c \
			  srcs/ft_memcpy.c \
			  srcs/ft_strcmp.c \
			  srcs/ft_putstr.c \
			  srcs/ft_atoi.c \
			  srcs/ft_itoa.c \
			  srcs/ft_convert_base.c \
			  srcs/ft_calloc.c \
			  srcs/ft_strstr.c \
			  srcs/ft_strcpy.c \
			  srcs/ft_strcat.c \
			  srcs/ft_str_tocase.c \
			  srcs/ft_str_is.c \
			  srcs/ft_swap.c \
			  srcs/ft_factorial.c \
			  srcs/ft_power.c \
			  srcs/ft_strtrm.c \
			  srcs/ft_strsmp.c \
			  srcs/ft_strjoin.c \
			  srcs/ft_strtoi.c \
			  srcs/ft_strdup.c \
			  srcs/ft_strspn.c \
			  srcs/ft_strtok.c \
			  srcs/ft_strpbrk.c \
			  srcs/ft_strsplit.c \
			  srcs/ft_strrev.c \
			  srcs/ft_strchr.c \
			  srcs/ft_memset.c \
			  srcs/ft_putnbr.c \
			  srcs/ft_check_numeric_base.c \
			  srcs/ft_atoi_base.c \
			  srcs/ft_itoa_base.c \
			  srcs/ft_memmem.c \
			  srcs/ft_bzero.c \
			  srcs/ft_memmove.c \
			  srcs/ft_memchr.c \
			  srcs/ft_memcmp.c \
			  srcs/ft_chr_is.c \
			  srcs/ft_chr_tocase.c \
			  srcs/ft_substr.c \
			  srcs/ft_strtrim.c \
			  srcs/ft_strmapi.c \

SRCS_BONUS	= \
			  srcs/ft_lstnew.c \
			  srcs/ft_lstadd.c \
			  srcs/ft_lstsize.c \
			  srcs/ft_lstlast.c \
			  srcs/ft_lstdel.c \
			  srcs/ft_lstiter.c \

ASMSRCS		= \

LIB_NAMES	= \

HEADERS		= \
			  includes \

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

OBJS		= ${SRCS:.c=.o} $(ASMSRCS:.asm=.o)
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
DEPS		= ${SRCS:.c=.d}
DEPS_BONUS	= ${SRCS_BONUS:.c=.d}
CC			= gcc -no-pie
CCWFLGS		= -Wall -Wextra -Werror
CCDBGFLGS	= -fsanitize=address -g
CCO1FLGS	= -O1 -march=native
CCO2FLGS	= -O2 -march=native
CCO3FLGS	= -O3 -march=native
DEPSFLAGS	= -MMD -MP
RM			= rm -f
MAKE		= make -C
AR			= ar
ARFLAGS		= rc
NASM		= nasm
NASMFLAGS	= -felf64

.PHONY: all clean fclean re bonus

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(AR) $(ARFLAGS) $@ $(OBJS)

bonus : $(OBJS) $(OBJS_BONUS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

$(LIB_PATHS) :
		$(MAKE) $(dir $@)

all : $(NAME)

clean :
		-$(RM) $(OBJS) $(DEPS)

fclean : clean
		-$(RM) $(NAME)

re : fclean all

%.o : %.asm Makefile
		$(NASM) $(NASMFLAGS) -o $@ $<

-include $(DEPS)

%.o : %.c Makefile
		$(CC) $(CCWFLAGS) $(DEPSFLAGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@ $(LIB_LD) $(LIBS)
