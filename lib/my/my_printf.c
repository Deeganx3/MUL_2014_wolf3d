/*
** my_printf.c for my_printf in /home/pasteu_e/rendu/PSU_2014_my_printf
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sun Nov  9 19:52:48 2014 etienne pasteur
** Last update Mon Nov 24 20:57:05 2014 etienne pasteur
*/

#include <stdarg.h>
#include "./my.h"

int		print_percent(va_list *ap, int number)
{
  number = print_putchar('%', number);
  return (number);
}

int		vide(va_list *ap, int number)
{
  print_putchar('\r', number);
  print_putstr("/!\\ Warning : At least one of these flags does not exist !\n",number);
  return (-1);
}

int		init(int (*fptr[127])(va_list*, int))
{
  int		i;

  i = 0;
  while (i <= 127)
    {
      fptr[i] = &vide;
      i = i + 1;
    }
  fptr['d'] = &print_num;
  fptr['i'] = &print_num;
  fptr['s'] = &print_str;
  fptr['c'] = &print_char;
  fptr['o'] = &print_octal;
  fptr['b'] = &print_bin;
  fptr['x'] = &print_hex_min;
  fptr['X'] = &print_hex_maj;
  fptr['S'] = &print_str_octal;
  fptr['u'] = &print_num_u;
  fptr['p'] = &print_addr;
  fptr['%'] = &print_percent;
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;
  int		number;
  int		(*fptr[127])(va_list*, int);

  va_start(ap, format);
  i = 0;
  number = 0;
  init(fptr);
  while (format[i])
    {
      if (format[i] == '%')
	{
	  i = i + 1;
	  number = fptr[format[i]](&ap, number);
	  if (number == -1)
	    break;
	}
      else
	number = print_putchar(format[i], number);
      i = i + 1;
    }
  va_end(ap);
  return (number);
}
