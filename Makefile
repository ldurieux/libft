NAME		= libft.a

SRCS		= \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_putstr_fd.c \
			  ft_split.c \
			  ft_strnstr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strncmp.c \
			  ft_strrchr.c \
			  ft_atoi.c \
			  ft_atoi_base.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_check_numeric_base.c \
			  ft_convert_base.c \
			  ft_factorial.c \
			  ft_itoa.c \
			  ft_itoa_base.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmem.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_power.c \
			  ft_str_is.c \
			  ft_str_tocase.c \
			  ft_strcat.c \
			  ft_strchr.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_strdup.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlen.c \
			  ft_strmapi.c \
			  ft_strpbrk.c \
			  ft_strrev.c \
			  ft_strsmp.c \
			  ft_strsplit.c \
			  ft_strspn.c \
			  ft_strstr.c \
			  ft_strtoi.c \
			  ft_strtok.c \
			  ft_strtrim.c \
			  ft_strtrm.c \
			  ft_substr.c \
			  ft_swap.c \

SRCS_BONUS	= \
			  ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstmap.c \
			  ft_lstiter.c \
			  ft_lstlast.c \
			  ft_lstnew.c \
			  ft_lstsize.c \

ASMSRCS		= \

LIB_NAMES	= \

HEADERS		= \
			  . \

LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

OBJS		= ${SRCS:.c=.o} $(ASMSRCS:.asm=.o)
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
DEPS		= ${SRCS:.c=.d}
DEPS_BONUS	= ${SRCS_BONUS:.c=.d}
CC			= cc
CCWFLGS		= -Wall -Wextra -Werror
CCDBGFLGS	= -fsanitize=address -g
CCO1FLGS	= -O1 -march=native
CCO2FLGS	= -O2 -march=native
CCO3FLGS	= -O3 -march=native
DEPSFLAGS	= -MMD -MP
RM			= rm -f
MAKE		= make -C
AR			= ar
ARFLAGS		= rcs
NASM		= nasm
NASMFLAGS	= -felf64

.PHONY: all clean fclean re bonus

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_BONUS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

$(LIB_PATHS) :
		$(MAKE) $(dir $@)

all : $(NAME)

clean :
		-$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS)

fclean : clean
		-$(RM) $(NAME)

re : fclean all

%.o : %.asm Makefile
		$(NASM) $(NASMFLAGS) -o $@ $<

-include $(DEPS)

%.o : %.c Makefile
		$(CC) $(CCWFLGS) $(DEPSFLAGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@ $(LIB_LD) $(LIBS)
