/*
** my_strncpy.c for my_strncpy in /home/pasteu_e/rendu/Piscine_C_J06/ex_02
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Mon Oct  6 10:41:18 2014 etienne pasteur
** Last update Tue Oct  7 10:07:11 2014 etienne pasteur
*/

int	compteur(char *src)
{
  int	i;
  int	compt;

  i = 0;
  compt = 0;
  while (src[i] != '\0')
    {
      compt = compt + 1;
      i = i + 1;
    }
  return (compt);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	compt;

  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  compt = compteur(src);
  if (n > compt)
    dest[compt] = '\0';
  return (dest);
}
