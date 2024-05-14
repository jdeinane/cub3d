# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 17:17:38 by jubaldo           #+#    #+#              #
#    Updated: 2024/05/14 17:24:42 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3

LFLAGS		=	libmlx.a libmlx_Linux.a -lX11 -lXext

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C minilibx-linux/ && mv minilibx-linux/libmlx.a . && mv minilibx-linux/libmlx_Linux.a .
			$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
			@echo "\033[32m ~~ cub3d successfully created! ~~"
			@echo "$$BIBOU"

clean:
			make clean -C minilibx-linux/
			rm -rf $(OBJS)
			@echo "\033[31m ~~ cub3d successfully deleted! ~~"
			@echo "$$PQ"

fclean:		clean
			rm -rf $(NAME) libmlx.a libmlx_Linux.a
			@echo "\033[31m ~~ cub3d successfully fdeleted! ~~"
			@echo "$$PQ"

re:			fclean all

.PHONY:		all clean fclean re


info: bibou
define BIBOU

            _    _____     _ 
  ___ _   _| |__|___ /  __| |
 / __| | | | '_ \ |_ \ / _` |
| (__| |_| | |_) |__) | (_| |
 \___|\__,_|_.__/____/ \__,_|
                             

endef
export BIBOU

info: pq
define PQ

 .--""--.___.._
(  <__>  )     `-.
|`--..--'|      <|      cleaning  ....
|       :|       /
|       :|--""-./
`.__  __;' 
    ""
endef
export PQ
