# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowpea <esnowpea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 13:56:52 by esnowpea          #+#    #+#              #
#    Updated: 2020/01/14 10:42:01 by esnowpea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L./libft

LDHEAD = ./libft/inc/

LDLIBS = -lft

SRC_NAME =  main.c \
            ft_printf.c \
            parsing.c \
            ft_c.c \
            ft_s.c \
            ft_d.c

OBJ = ./obj/

SRC = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)

HEAD = ./inc/

.PHONY: all clean fclean re

all: create_obj $(NAME)

$(NAME): $(addprefix $(OBJ), $(OBJ_NAME))
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[0;32m$(NAME)'s program created.\033[0m"

$(OBJ)%.o: $(SRC)%.c
	@$(CC) $(CFLAGS) -I $(HEAD) -I $(LDHEAD) -o $@ -c $<

create_obj:
	@mkdir -p $(OBJ)

clean:
	@rm -rf $(addprefix $(OBJ), $(OBJ_NAME))
	@rm -rf $(OBJ)
	@echo "\033[0;32m$(NAME)'s .o files deleted.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;32m$(NAME) Project fully cleaned.\033[0m"

re: fclean all
