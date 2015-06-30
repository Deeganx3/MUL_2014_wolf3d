/*
** my_printf_func1.c for Fonctions_pour_my_printf in /home/pasteu_e/rendu/PSU_2014_my_printf
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sat Nov 15 21:05:19 2014 etienne pasteur
** Last update Mon Nov 24 20:57:22 2014 etienne pasteur
*/

#include <stdarg.h>
#include "./my.h"

int		print_char(va_list *ap, int number)
{
  unsigned char	c;

  c = va_arg(*ap, int);
  number = print_putchar(c, number);
  return (number);
}

int		print_str(va_list *ap, int number)
{
  char		*str;

  str = va_arg(*ap, char*);
  number = print_putstr(str, number);
  return (number);
}

int		print_num(va_list *ap, int number)
{
  int		n;

  n = va_arg(*ap, int);
  number = print_put_nbr(n, number);
  return (number);
}

int		print_octal(va_list *ap, int number)
{
  unsigned int	nb;

  nb = va_arg(*ap, unsigned int);
  number = print_putnbr_base(nb, "01234567", number);
  return (number);
}

int		print_bin(va_list *ap, int number)
{
  unsigned int	nb;

  nb = va_arg(*ap, unsigned int);
  number = print_putnbr_base(nb, "01", number);
  return (number);
}
