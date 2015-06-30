/*
** my_power_rec.c for my_power_rec in /home/pasteu_e/rendu/Piscine_C_J05
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Fri Oct  3 12:15:58 2014 etienne pasteur
** Last update Tue Oct  7 11:33:41 2014 etienne pasteur
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  if (power == 1)
    return (nb);
  if (nb > 8 && power > 9)
    return (0);
  while (power > 1)
    return (nb * my_power_rec(nb, power - 1));
}
