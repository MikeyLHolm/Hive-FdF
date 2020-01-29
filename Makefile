# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 14:16:04 by mlindhol          #+#    #+#              #
#    Updated: 2019/12/18 09:33:59 by mlindhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRC = color.c controls.c draw.c main.c menu.c projection.c read_file.c 

OBJ = $(subst .c,.o,$(SRC))

FLAGS=-Wall -Wextra -Werror

CC=gcc

HEADER=./includes/fdf.h

MLX = -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIB_NAME=libft.a
LIB_PATH=./libft/
LIB=$(LIB_PATH)$(LIB_NAME)

COLOR_RESET=\033[0m
COLOR_PENDING=\033[01;33m
COLOR_SUCCESS=\033[1;32m
COLOR_DEFAULT=\033[1;34m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(LIB_NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH)
	@echo "\033[A\033[K\033[A"
	@echo "$(LIB_NAME) [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@$(CC) $(FLAGS) $(OBJ) $(MLX) $(LIB) -o $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "        [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"

run:
	./fdf test_maps/42.fdf

debug:
	gcc color.c controls.c draw.c main.c menu.c projection.c read_file.c $(MLX) libft/libft.a -g -o $(NAME)

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -rfv $(NAME)

re: fclean all

.PHONY: all clean debug fclean re run
