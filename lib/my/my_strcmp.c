/*
** my_strcmp.c for my_strcmp in /home/pasteu_e/rendu/Piscine_C_J06/ex_05
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Mon Oct  6 14:57:35 2014 etienne pasteur
** Last update Wed Oct  8 19:47:18 2014 etienne pasteur
*/

int	my_strcmp(char *s1, char *s2)
{
  int   compt;
  int	retur;

  compt = 0;
  while (s1[compt] == s2[compt] && s1[compt] != '\0' && s2[compt] != '\0')
    {
      compt = compt + 1;
    }
  retur = s1[compt] - s2[compt];
  return (retur);
}
