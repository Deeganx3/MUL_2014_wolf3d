##
## Makefile for Makefile_for_test_pixel.c in /home/pasteu_e/rendu/Piscine_C_J14
## 
## Made by etienne pasteur
## Login   <pasteu_e@epitech.net>
## 
## Started on  Thu Oct 23 19:50:38 2014 etienne pasteur
## Last update Tue Jan 20 16:33:53 2015 etienne pasteur
##

CC	= cc

RM	= rm -f

CFLAGS	= -I/usr/X11R6/include -O3 -w

NAME	= libmlx.a

SRCS	= mlx_init.c \
	  mlx_new_window.c \
	  mlx_pixel_put.c \
	  mlx_loop.c \
	  mlx_mouse_hook.c \
	  mlx_key_hook.c \
	  mlx_expose_hook.c \
	  mlx_loop_hook.c \
	  mlx_int_anti_resize_win.c \
	  mlx_int_do_nothing.c \
	  mlx_int_wait_first_expose.c \
	  mlx_int_get_visual.c \
	  mlx_flush_event.c \
	  mlx_string_put.c \
	  mlx_new_image.c \
	  mlx_get_data_addr.c \
	  mlx_put_image_to_window.c \
	  mlx_get_color_value.c \
	  mlx_clear_window.c \
	  mlx_xpm.c \
	  mlx_int_str_to_wordtab.c \
	  mlx_destroy_window.c \
	  mlx_int_param_event.c \
	  mlx_int_set_win_event_mask.c \
	  mlx_hook.c \
	  mlx_rgb.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(NAME) ../
	cp $(NAME) libmlx_$(HOSTTYPE).a
	cp $(NAME) ../libmlx_$(HOSTTYPE).a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
