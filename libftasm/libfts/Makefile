NAME = libfts.a
NA = nasm
NAFLAGS = -g -f elf64 -DLINUX -p includes/syscalls.s
AR = ar
ARFLAGS = -rc
HEADERFILES = includes/libfts.h
SRCSDIR = ./srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
SRCSFILES = ft_bzero.s \
			ft_strcat.s \
			ft_isalpha.s \
			ft_isdigit.s \
			ft_isalnum.s \
			ft_isascii.s \
			ft_isprint.s \
			ft_toupper.s \
			ft_tolower.s \
			ft_puts.s \
			ft_strlen.s \
			ft_memset.s \
			ft_memcpy.s \
			ft_strdup.s \
			ft_cat.s \
			ft_isupper.s \
			ft_islower.s \
			ft_ispunct.s \
			ft_isspace.s \
			ft_abs.s \
			ft_atoi.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	ranlib $@

%.o: %.s $(HEADERFILES)
	$(NA) $(NAFLAGS) $< -o $@

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
