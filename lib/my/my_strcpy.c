/*
** my_strcpy.c for my_strcpy in /home/pasteu_e/rendu/Piscine_C_J06/ex_01
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Mon Oct  6 09:25:23 2014 etienne pasteur
** Last update Mon Oct  6 10:19:59 2014 etienne pasteur
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
