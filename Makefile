# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 11:22:48 by rvan-aud          #+#    #+#              #
#    Updated: 2021/07/16 12:02:22 by rvan-aud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	main.c			\
			modgnl.c		\
			modgnl_utils.c	\
			move_player.c	\
			utils.c			\

NAME	= so_long

CC		= gcc

RM		= rm -f

CFLAGS	= -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re