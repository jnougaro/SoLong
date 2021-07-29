# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 10:45:42 by jnougaro          #+#    #+#              #
#    Updated: 2021/07/29 10:54:36 by jnougaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= srcs/handle_event.c \
		  	srcs/display_image.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/read_map.c \
			srcs/utils.c \
			srcs/put_texture.c \
			srcs/parsing.c \
			srcs/treat_errors.c \
			srcs/main.c \
			srcs/treat_errors_2.c \
			srcs/put_texture_2.c \
			srcs/handle_player.c \
			srcs/handle_player_d.c \
			srcs/handle_player_a.c \
			srcs/handle_player_s.c \
			srcs/handle_player_w.c \
			srcs/destroy_image.c \
			srcs/init_image.c

OBJS	= ${SRCS:.c=.o}

LD_FLAGS = -L mlx

MLX_FLAGS = -lm -lmlx -lXext -lX11

HEAD	= -I includes -I mlx

CC 	= clang
RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C mlx/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} ${MLX_FLAGS}

all:		${NAME}

clean:
		${RM} ${OBJS}
		make clean -C mlx

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
