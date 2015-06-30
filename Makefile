## Makefile for Makefile_for_wolf in /home/pasteu_e/rendu/MUL_2014_wolf3d
## 
## Made by etienne pasteur
## Login   <pasteu_e@epitech.net>
## 
## Started on  Thu Oct 23 19:50:38 2014 etienne pasteur
## Last update Wed Jul  1 01:38:07 2015 Etienne Pasteur
##

CC	= cc

RM	= rm -f

NAME	= wolf3d

SRCS	= wolf.c \
	  draw.c \
	  events.c \
	  init.c \
	  calculs.c \
	  joystick.c \
	  mini_map.c \
	  utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	make -C lib/minilibx/
	make -C lib/my/
	$(CC) $(OBJS) -O3 -g -L./lib/ -lSDL2_image -lSDL2 -lSDL2_ttf -lSDL2_mixer -lm -ldl -pthread -lm -lmlx -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lmy -o $(NAME)
	#$(CC) $(OBJS) -O3 -g -L./lib/ -lSDL2_image -lSDL2 -lSDL2_ttf -lSDL2_mixer -lm -ldl -pthread -lftgl -lftdi -lfreetype -lm -lmlx -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lmy -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) -O3 -c $(SRCS) -I include

clean:
	make -C lib/minilibx/ clean
	make -C lib/my/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C lib/minilibx/ fclean
	make -C lib/my/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
