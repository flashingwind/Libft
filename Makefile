SRCS = ft_additonal_iter.c ft_additonal_putfd.c ft_additonal_string.c \
       ft_additonal_strjoin.c ft_ctype.c ft_ctype2.c ft_stdlib.c \
	   ft_string_bsd.c ft_string.c
CC = clang
AR = ar
CFLAGS = -Wall -Wextra -Werror -std=c99
OBJS = $(SRCS:%.c=%.o)
NAME = libft.a

.PHONY: all fclean clean re

$(NAME):		$(OBJS)
				$(AR) r $@ $?


all:	$(NAME)

$(OBJS): $(SRCS)
				$(CC) -c $(CFLAGS) $?


fclean: clean
				rm -f $(NAME)

clean:
				rm -f *.o

re: fclean all

