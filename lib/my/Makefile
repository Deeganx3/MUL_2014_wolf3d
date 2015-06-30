##
## Makefile for Makefile_for_lib in /home/pasteu_e/rendu/Piscine_C_J11/lib/my
## 
## Made by etienne pasteur
## Login   <pasteu_e@epitech.net>
## 
## Started on  Mon Oct 20 09:46:38 2014 etienne pasteur
## Last update Tue Jan 20 16:34:13 2015 etienne pasteur
##

CC	= cc

RM	= rm -f

NAME	= libmy.a

SRCS	= my_find_prime_sup.c \
	  my_getnbr.c \
	  my_isneg.c \
	  my_is_prime.c \
	  my_power_rec.c \
	  my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_revstr.c \
	  my_showstr.c \
	  my_sort_int_tab.c \
	  my_square_root.c \
	  my_strcapitalize.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_strlcat.c \
	  my_strlen.c \
	  my_strlowcase.c \
	  my_strncat.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_strupcase.c \
	  my_swap.c \
	  print_putchar.c \
	  print_put_nbr.c \
	  print_putnbr_base.c \
	  print_putstr.c \
	  my_printf.c \
	  my_printf_func1.c \
	  my_printf_func2.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME) $(OBJS) move

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

move:
	cp $(NAME) ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all move clean fclean re
