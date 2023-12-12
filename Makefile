# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguntepe <@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 09:07:02 by sguntepe          #+#    #+#              #
#    Updated: 2023/12/12 19:17:58 by sguntepe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g
SRCS    = main.c read_file.c read_file_utils.c file_parcer.c inits.c \
			file_parcer_utils.c
OBJS    = $(addprefix obj/, $(SRCS:.c=.o))
GREEN   = \033[0;32m
RED     = \033[0;31m
CODE    = \033[m

all: obj $(NAME)

obj:
	@mkdir -p obj

$(NAME):  $(OBJS) libft
	@$(CC) $(CFLAGS) $(OBJS) ./include/libft/libft.a  -o $@ ./include/libft/libft.a
	@echo "$(GREEN)[✓]$(CODE)"

obj/%.o: %.c
	@$(CC) $(CFLAGS)  -c $< -o $@

libft:
	@make -C ./include/libft

clean:
	@rm -rf $(OBJS)
	@echo "$(RED)[DELETED]$(CODE)"
	@rm -f ./include/libft/*.o
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@rm -f ./include/libft/*.a

re: fclean all

.PHONY: all clean fclean re
