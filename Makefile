#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/03 05:02:18 by hbouchet          #+#    #+#              #
#    Updated: 2017/09/05 06:29:42 by hbouchet         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fractol
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -Ofast #-g3 -fsanitize=address
CFLAGSMLX	=	-L minilibx -lmlx -framework OpenGL -framework AppKit

LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a

INC_DIR		=	includes
INCS		=	-I $(INC_DIR) -I $(LIB_PATH)

SRC_DIR		=	srcs
SRC			=	fractol.c	\
				fractales.c \
				math.c		\
				putpixel.c	\
				control.c


OBJ_DIR		=	obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: $(NAME)

$(NAME): obj $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(CFLAGSMLX) $(LIB)

obj:
	mkdir obj

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
