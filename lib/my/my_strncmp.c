/*
** my_strncmp.c for my_strncmp in /home/pasteu_e/rendu/Piscine_C_J06/ex_06
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Mon Oct  6 20:41:29 2014 etienne pasteur
** Last update Mon Oct  6 23:15:59 2014 etienne pasteur
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   compt;
  int   cmp;

  compt = 0;
  while (s1[compt] == s2[compt])
    {
      compt = compt + 1;
    }
  if (n - 1 >= compt)
    cmp = s1[compt] - s2[compt];
  else
    return (0);
  return (cmp);
}
