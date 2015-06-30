/*
** print_putstr.c for print_putstr in /home/pasteu_e/rendu/PSU_2014_my_printf/lib/my
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sun Nov 16 19:18:43 2014 etienne pasteur
** Last update Sun Nov 16 19:18:44 2014 etienne pasteur
*/

int	print_putstr(char *str, int number)
{
  while (*str != '\0')
    {
      number = print_putchar(*str, number);
      str = str + 1;
    }
  return (number);
}
