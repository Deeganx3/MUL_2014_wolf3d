/*
** my_square_root.c for my_square_root in /home/pasteu_e
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Wed Oct  8 01:08:27 2014 etienne pasteur
** Last update Wed Oct  8 13:25:21 2014 etienne pasteur
*/

int	my_square_root(int nb)
{
  int	a;

  a = 0;
  while (a * a != nb)
    {
      a = a + 1;
      if (a == nb / 2 + 1)
	return (0);
    }
  return (a);
}
