NAME = libft_asm
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I ./includes/ -I ./libfts/includes/
LDFLAGS = -L libfts/ -lfts
HEADERFILES = ft_ls_structs.h ft_ls.h
SRCSDIR = ./srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
SRCSFILES = main.c
OBJS = $(SRCS:.c=.o)
LIBFTS = libfts/libfts.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFTS):
	make -C libfts/

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C libfts/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	make -C libfts/ $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
