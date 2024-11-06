NAME = libft.a
HEADER = libft.h
SRCS =	ft_additonal_iter.c ft_additonal_itoa.c ft_additonal_putfd.c \
ft_additonal_string.c ft_additonal_string2.c ft_ctype.c ft_ctype2.c ft_stdlib.c \
ft_string_bsd.c ft_string.c ft_string2.c ft_string3.c ft_bonus.c ft_bonus2.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99
AR = ar
# OLD_SHELL := $(SHELL)
# SHELL = $(warning [Making: $@]   [Dependencies: $^]   [Changed: $?])$(OLD_SHELL)

.PHONY: all fclean clean re

$(NAME): $(OBJS)
	$(AR) r $@ $(?F)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
# 	gcc -nostartfiles -shared -o libft.so $(OBJS)

all: $(NAME)

bonus: $(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o

re: fclean all

