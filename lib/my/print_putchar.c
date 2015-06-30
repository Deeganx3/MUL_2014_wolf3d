/*
** print_putchar.c for print_putchar in /home/pasteu_e/rendu/PSU_2014_my_printf/lib/my
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sun Nov 16 19:17:45 2014 etienne pasteur
** Last update Sun Nov 16 19:17:46 2014 etienne pasteur
*/

int	print_putchar(char c, int number)
{
  write(1, &c, 1);
  number = number + 1;
  return (number);
}
