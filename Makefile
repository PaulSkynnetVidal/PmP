##
## Makefile for pisc in /home/vidal_p/rendu/Pmp
## 
## Made by paul vidal
## Login   <vidal_p@epitech.net>
## 
## Started on  Thu Jul 17 09:27:41 2014 paul vidal
## Last update Fri Jul 18 06:28:46 2014 paul vidal
##

CC		= gcc

RM		= rm -f

NAME		= Pmp

SRC_D		= srcs

INCLUDE_D	= include

SRC_F		= main.c		\
		  str.c			\
		  number.c		\
		  put_pxl.c		\
		  mlx_fct.c		\
		  triangle.c		\
		  main2.c		

SRCS		= $(addprefix $(SRC_D)/, $(SRC_F))

OBJS		= $(SRCS:.c=.o)

MLX		= -L/ -lmlx -lXext -lX11 -lm

CFLAGS		= -W -Wall -Wextra -pedantic -ansi -I $(INCLUDE_D)

$(NAME)		: $(OBJS)
		  $(CC) -o $(NAME) $(OBJS) $(MLX)

all		: $(NAME)

clean		:
		  $(RM) $(OBJS)

fclean		: clean
		  $(RM) $(NAME)

re		: fclean all

.PHONY		: all clean fclean
