/*
** print_put_nbr.c for print_put_nbr in /home/pasteu_e/rendu/PSU_2014_my_printf/lib/my
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sun Nov 16 19:18:23 2014 etienne pasteur
** Last update Sun Nov 16 19:18:24 2014 etienne pasteur
*/

int	print_put_nbr(int nb, int number)
{
  if (nb==0)
    {
      number = print_putchar(48, number);
      return (number);
    }
  if (nb < 0)
    {
      nb = -nb;
      number = print_putchar(45, number);
    }
  if (nb < 10)
    {
      number = print_putchar(48 + nb, number);
      return (number);
    }
  number = print_put_nbr(nb / 10, number);
  number = print_putchar(nb % 10 + 48, number);
  return (number);
}
