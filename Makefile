CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -lmlx -framework OpenGL -framework AppKit
HEADER	= include/*.h
SRCS	= get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c \
		  srcs/verif_map.c \
		  srcs/parsing.c \
		  srcs/main.c \
		  srcs/draw.c \
		  srcs/init.c \
		  srcs/move.c \
		  srcs/calcul.c \
		  srcs/ft_func.c
RM		= rm -f
NAME	= so_long

OBJS 	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $@ $^ $(CFLAGS) -I$(HEADER) $(MLX)

clean:		
			$(RM) srcs/*.o

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY : all clean fclean re
