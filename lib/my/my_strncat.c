/*
** my_strncat.c for my_strncat in /home/pasteu_e/rendu/Piscine_C_J07/ex_01
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 13:57:54 2014 etienne pasteur
** Last update Tue Oct  7 14:54:39 2014 etienne pasteur
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int   compt;
  int   i;

  compt = 0;
  i = 0;
  while (dest[compt] != '\0')
    compt = compt + 1;
  while (i != nb && src[i] != '\0')
    {
      dest[compt] = src[i];
      compt = compt + 1;
      i = i + 1;
    }
  dest[compt] = '\0';
  return (dest);
}
