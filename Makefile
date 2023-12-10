# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 09:07:02 by sguntepe          #+#    #+#              #
#    Updated: 2023/12/10 09:07:03 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = main.c read_mapfile.c inits.c map_control.c
OBJS    = $(addprefix obj/, $(SRCS:.c=.o))
GREEN   = \033[0;32m
RED     = \033[0;31m
CODE    = \033[m

all: obj $(NAME)

obj:
	@mkdir -p obj

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ ./include/libft/libft.a
	@echo "$(GREEN)[✓]$(CODE)"

obj/%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@
	
clean:
	@rm -rf $(OBJS)
	@echo "$(RED)[DELETED]$(CODE)"
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
