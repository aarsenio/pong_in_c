# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarsenio <aarsenio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2023/02/10 15:10:07 by aarsenio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= 	gcc-10 -Wall -Wextra -Werror #-g -fsanitize=address
RM			= 	/bin/rm -f
NAME		= 	pong
INCLUDES	= 	-Iheaders/
MILIB		=	-I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit

SRCS		=   main.c $(shell find src/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)


MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME)

$(NAME): $(OBJS) 
	@$(MAKE) -s -C mlx_linux
	@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c $(MLX_LIB)
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED EXECUTABLE\033[0m"

re: fclean all

run:
	make re && make clean && clear && ./pong

.PHONY: all re clean fclean m
