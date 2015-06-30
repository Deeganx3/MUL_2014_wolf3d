/*
** my_sort_int_tab.c for my_sort_int_tab in /home/pasteu_e/rendu/Piscine_C_J04
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Wed Oct  8 10:26:56 2014 etienne pasteur
** Last update Wed Oct  8 12:16:39 2014 etienne pasteur
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	tmp;
  int	pos;
  int	count;
  int	tmpo;

  count = 0;
  pos = 0;
  while (pos != size - 1)
    {
      while (count != size - 1)
	{
	  if (count == pos)
	    tmp = pos;
	  if (tab[count] < tab[tmp])
	    tmp = count;
	  count = count + 1;
	}
      tmpo = tab[pos];
      tab[pos] = tab[tmp];
      tab[tmp] = tmpo;
      pos = pos + 1;
      count = pos;
    }
}
