# b3TT€r_n3®F * b3TT€r_n3®F * b3TT€r_n3®F * b3TT€r_n3®F * b3TT€r_n3®F * b3TT€r #
# ██████  ██████ ████████████ ██████ ██████     ███   ██ ██████ ██████  ██████ #
# ██   ██ ██       ██    ██   ██     ██   ██    ████  ██ ██     ██   ██ ██     #
# ██████  ████     ██    ██   ████   ██████     ██ █  ██ ████   ██████  ██████ #
# ██   ██ ██       ██    ██   ██     ██   ██    ██ ██ ██ ██     ██   ██ ██     #
# ██████  ██████   ██    ██   ██████ ██   ██ ██ ██  ████ ██████ ██ ::██:██:    #
#    makefile                                           :+:      :+:    :+:    #
#    By: hbruvry <marvin@42.fr>                       +:+ +:+         +:+      #
#                                                   +#+  +:+       +#+         #
#    Created: 2018/06/12 04:20:00 by hbruvry      +#+#+#+#+#+   +#+            #
#    Updated: 2018/12/17 04:20:00 by hbruvry           #+#    #+#              #
# n3®F * b3TT€r_n3®F * b3TT€r_n3®F * b3TT€r_n3®F * b3 ### n ########.fr n3®F * #

NAME =		rtv1

ifeq ($(OS),Windows_NT)
	LIBMLX = $(MLXWIN)
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		LIBMLX = $(MLXMAC)
	endif
endif

MLXWIN =	-L /usr/local/lib/ -lmlx -lX11.dll -lXext.dll
MLXMAC =	-L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

# MLXMAC =	-L /usr/X11/lib/ -lmlx -framework OpenGL -framework Appkit

LIBFT =		LIBFT
LIBRT =		LIBRT
LIBS =		librt/librt.a libft/libft.a

CC =		clang
CFLAGS =	-Wall -Wextra -Werror

SRCS =		sources/main.c \
			sources/ft_getenv.c \
			sources/ft_setobj.c \
			sources/ft_setenv.c \
			sources/ft_lfill.c \
			sources/ft_filecopy.c \
			sources/ft_filecheck.c \
			sources/ft_putenv.c \
			sources/ft_intersect.c \
			sources/ft_drawscene.c \
			sources/ft_drawtext.c \

OBJS =		$(SRCS:.c=.o)

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBRT)
	@gcc $(CFLAGS) -o $(NAME) -I /usr/local/include/ $(OBJS) $(LIBS) $(LIBMLX)
	@printf "$(_GREEN)rtv1 compiled\n$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT)
	@$(MAKE) clean -C $(LIBRT)
	@rm -f $(OBJS)
	@printf "libft cleaned\n"
	@printf "librt cleaned\n"
	@printf "rtv1 cleaned\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(LIBRT)
	@rm -f $(NAME)
	@printf "rtv1 fcleaned\n"

re: fclean all

.PHONY: libft librt clean fclean all re
