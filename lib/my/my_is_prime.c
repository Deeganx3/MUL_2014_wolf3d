/*
** my_is_prime.c for my_is_prime in /home/pasteu_e/rendu/Piscine_C_J05
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Wed Oct  8 13:26:57 2014 etienne pasteur
** Last update Wed Oct  8 14:09:24 2014 etienne pasteur
*/

int	my_is_prime(int nb)
{
  int	a;
  int	tmp;

  if (nb == 0 || nb == 1)
    return (0);
  a = 2;
  while (a < nb / 2)
    {
      tmp = nb / a;
	if (a * tmp == nb)
	    return (0);
      a = a + 1;
    }
  return (1);
}
