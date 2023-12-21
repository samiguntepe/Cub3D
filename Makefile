# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 09:07:02 by sguntepe          #+#    #+#              #
#    Updated: 2023/12/21 16:56:15 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= cub3D
CC      	= gcc
CFLAGS  	= -Wall -Wextra -Werror -g
SRCS    	= ./src/main.c ./src/read_file.c ./src/file_parcer.c \
			 ./src/inits.c ./src/move.c ./src/raycast.c \
			 ./src/file_parcer_utils.c ./src/utils.c ./src/file_split.c \ 
			 ./src/map_control.c ./src/game.c ./src/rotate.c \
OBJS    	= $(addprefix obj/, $(SRCS:.c=.o))
OFLAGS		= -framework OpenGL -framework AppKit
MINILIBX	= ./minilibx/libmlx.a
GREEN   	= \033[0;32m
RED     	= \033[0;31m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
CODE    	= \033[m

all: obj $(NAME)

obj:
	@mkdir -p obj

$(NAME):  $(OBJS) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OFLAGS) $(OBJS) $(MINILIBX) -o $@
	@echo "$(GREEN)[✓]$(CODE)"

obj/%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@

$(MINILIBX):
	@make -s -C ./minilibx &
	@for i in {1..4}; do \
	printf "\r$(PURPLE)[%-4s]$(CODE)" "$$(head -c $$i < /dev/zero | tr '\0' '#')"; \
        sleep 1; \
    done
	@echo ""
	@wait

clean:
	@rm -rf $(OBJS)
	@rm -f ./minilibx/*.o
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@rm -rf ./minilibx/*.a

re: fclean all

norm:
	@norminette src

.PHONY: all clean fclean re norm
