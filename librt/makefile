# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 11:29:51 by hbruvry           #+#    #+#              #
#    Updated: 2018/11/16 18:05:36 by hbruvry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_vclr.c \
			ft_vset.c \
			ft_vsum.c \
			ft_vsub.c \
			ft_vmul.c \
			ft_vdiv.c \
			ft_vdot.c \
			ft_vsqrd.c \
			ft_vnorm.c \
			ft_vfill.c \
			ft_vpolartocartesian.c \
			ft_vcross.c \
			ft_vrotx.c \
			ft_vroty.c \
			ft_vrotz.c \
			ft_vrotxyz.c \
			ft_m4b4subbloc.c \
			ft_m3b3det.c \
			ft_m4b4trans.c \
			ft_m4b4scale.c \
			ft_m4b4inv.c \
			ft_vtom4b4.c \
			ft_m3b3set.c \
			ft_m3b3rot.c \
			ft_m3b3rotx.c \
			ft_m3b3roty.c \
			ft_m3b3rotz.c \
			ft_vtom3b3.c \
			ft_m3b3mul.c \
			ft_m3b3scale.c \
			ft_m3b3setdiag.c \
			ft_m3b3inv.c \
			ft_m4b4set.c \
			ft_m3b3print.c \
			ft_vprint.c \

OBJS =		$(SRCS:.c=.o)

NAME =		librt.a

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(CFLAGS) -I. -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(_GREEN)librt compiled\n$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@printf "librt fcleaned\n"

re: fclean all

.PHONY : clean fclean all re


