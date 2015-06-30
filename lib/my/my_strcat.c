/*
** my_strcat.c for my_strcat in /home/pasteu_e/rendu/Piscine_C_J07/ex_01
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 12:18:05 2014 etienne pasteur
** Last update Mon Oct 13 10:37:48 2014 etienne pasteur
*/

char	*my_strcat(char *dest, char *src)
{
  int	compt;
  int	i;

  compt = 0;
  i = 0;
  while (dest[compt] != '\0')
    compt = compt + 1;
  while (src[i] != '\0')
    {
      dest[compt] = src[i];
      compt = compt + 1;
      i = i + 1;
    }
  dest[compt] = '\0';
  return (dest);
}
