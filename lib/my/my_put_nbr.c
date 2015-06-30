/*
** my_put_nbr.c<2> for my_put_nbr in /home/pasteu_e/rendu/Piscine_C_J03
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 18:18:40 2014 etienne pasteur
** Last update Tue Oct 21 00:39:27 2014 etienne pasteur
*/

int	my_put_nbr(int nb)
{
  if (nb==0)
    {
      my_putchar(48);
      return (0);
    }
  if (nb < 0)
    {
      nb = -nb;
      my_putchar(45);
    }
  if (nb < 10)
    {
      my_putchar(48 + nb);
      return (0);
    }
  my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (0);
}
