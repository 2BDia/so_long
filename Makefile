# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 11:22:48 by rvan-aud          #+#    #+#              #
#    Updated: 2021/07/27 15:38:35 by rvan-aud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	srcs/main.c			\
			srcs/animations.c	\
			srcs/check_elem.c	\
			srcs/check_map.c	\
			srcs/close.c		\
			srcs/init.c			\
			srcs/modgnl_utils.c	\
			srcs/modgnl.c		\
			srcs/move_player.c	\
			srcs/utils.c		\
			srcs/parse_map.c	\
			srcs/read_map.c		\
			srcs/set_map.c		\

NAME	= so_long

CC		= gcc

RM		= rm -f

CFLAGS	= -I /usr/local/include -I includes -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
