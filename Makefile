NAME = libft.a
HEADER = libft.h
SRCS =	ft_additonal_iter.c ft_additonal_itoa.c ft_additonal_putfd.c ft_additonal_string.c ft_additonal_string2.c ft_ctype.c ft_ctype2.c ft_stdlib.c ft_string_bsd.c ft_string.c ft_string2.c ft_string3.c
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99
AR = ar
# OLD_SHELL := $(SHELL)
# SHELL = $(warning [Making: $@]   [Dependencies: $^]   [Changed: $?])$(OLD_SHELL)

.PHONY: all fclean clean re

$(NAME): $(OBJS)
	$(AR) r $@ $(?F)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

$(SRCS): $(HEADER)

all: $(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o

re: fclean all

