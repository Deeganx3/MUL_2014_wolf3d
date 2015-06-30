/*
** my_printf_func2.c for Fonctions_pour_my_printf in /home/pasteu_e/rendu/PSU_2014_my_printf
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sat Nov 15 21:06:56 2014 etienne pasteur
** Last update Mon Nov 24 20:57:38 2014 etienne pasteur
*/

#include <stdarg.h>
#include "./my.h"

int			print_hex_min(va_list *ap, int number)
{
  unsigned int		nb;

  nb = va_arg(*ap, unsigned int);
  number = print_putnbr_base(nb, "0123456789abcdef", number);
  return (number);
}

int			print_hex_maj(va_list *ap, int number)
{
  unsigned int		nb;

  nb = va_arg(*ap, unsigned int);
  number = print_putnbr_base(nb, "0123456789ABCDEF", number);
  return (number);
}

int			print_num_u(va_list *ap, int number)
{
  unsigned int		n;

  n = va_arg(*ap, unsigned int);
  number = print_put_nbr(n, number);
  return (number);
}

int			print_addr(va_list *ap, int number)
{
  void			*nb;
  unsigned long int	nbr;

  nb = va_arg(*ap, void*);
  nbr = (unsigned long int) nb;
  number = print_putstr("0x", number);
  number = print_putnbr_base(nbr, "0123456789abcdef", number);
  return (number);
}

int			print_str_octal(va_list *ap, int number)
{
  int			i;
  char			*str;

  i = 0;
  str = va_arg(*ap, char*);
  while (str[i] != '\0')
    {
      if (str[i] < 7)
	{
	  number = print_putstr("\\00", number);
	  number = print_putnbr_base(str[i], "01234567", number);
	}
      else if (str[i] >= 7 && str[i] < 32 || str[i] == 127)
	{
	  if (str[i] != 127)
	    number = print_putstr("\\0", number);
	  else
	    number = print_putchar('\\', number);
	  number = print_putnbr_base(str[i], "01234567", number);
	}
      else
	number = print_putchar(str[i], number);
      i = i + 1;
    }
  return (number);
}
