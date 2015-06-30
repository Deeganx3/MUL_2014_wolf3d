/*
** my_find_prime_sup.c for my_find_prime_sup in /home/pasteu_e/rendu/Piscine_C_J05
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Wed Oct  8 14:57:13 2014 etienne pasteur
** Last update Wed Oct  8 14:58:45 2014 etienne pasteur
*/

int     my_find_prime_sup(int nb)
{
  int   a;
  int   tmp;

  if (nb == 0 || nb == 1)
    nb = 2;
  a = 2;
  while (a <= nb / 2)
    {
      tmp = nb / a;
      if (a * tmp == nb)
        return (my_find_prime_sup(nb + 1));
      a = a + 1;
    }
  return (nb);
}
